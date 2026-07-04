# Config 模块

## 模块职责
Config 模块负责维护 Photon-RPC 框架的全局基础配置、编译期常量以及系统级的依赖配置选项（如内存管理模式、网络发送模式）。

## 核心文件
* [config.h](config.h)：提供基础常量、模式枚举和全局变量声明。
* [config.cpp](config.cpp)：定义全局配置变量并进行默认初始化。

## 核心类 / 函数
* 全局常量：
  * `photon::config::IO_URING_QUEUE_DEPTH`：io_uring 队列深度，默认 `131072`。
  * `photon::config::DEFAULT_PORT`：默认监听端口，值为 `8080`。
  * `photon::config::TCP_BACKLOG`：TCP 监听队列积压大小，默认 `8192`。
  * `photon::config::MAX_BODY_LEN`：最大报文长度限制，默认 `1MB`，用以防止异常大包导致内存溢出。
  * `photon::config::CACHE_LINE_SIZE`：缓存行大小，默认 `64` 字节，用以消除伪共享。
  * `photon::config::PHOTON_VERSION`：Photon-RPC 的版本标识。
* 配置枚举：
  * `photon::config::MemoryMode`：内存分配模式（`SLAB` 内存池 / `MALLOC` 系统堆分配）。
  * `photon::config::SendMode`：数据发送模式（`WRITEV` 零拷贝散射写 / `WRITE` 传统拷贝写）。
* 全局配置控制变量：
  * `photon::config::g_memory_mode`：全局内存分配模式变量。
  * `photon::config::g_send_mode`：全局网络发送模式变量。

## 工作流程
1. **编译期静态配置**：各模块在编译阶段直接使用该模块定义的常量（如 `CACHE_LINE_SIZE` 进行内存对齐）。
2. **启动期参数解析**：在系统启动时（例如在 `main.cpp` 中），通过命令行参数解析，可以动态修改全局配置变量 `g_memory_mode` 和 `g_send_mode` 的值。
3. **运行期行为控制**：在运行期，内存分配器（`slab`）与套接字发送器（`handler`）会根据这些全局变量决定底层具体的执行路径（例如是选用 SLAB 还是 new/delete 分配内存，或者采用 write 还是 writev 发送数据）。

## 与其他模块的关系
* **内存管理（Slab）**：`Slab` 模块分配内存时依赖 `g_memory_mode` 决定是使用预分配内存池还是直接调用系统 `new/delete`。
* **协程与 Task 模块**：协程任务创建时依赖 `g_memory_mode` 控制其物理帧的内存分配方式。
* **连接处理器（Handler）**：依赖 `g_send_mode` 选择性能最优的数据写入策略。
