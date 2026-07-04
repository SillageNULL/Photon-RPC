# Protocol 模块

## 模块职责
Protocol 模块负责定义 Photon-RPC 的网络二进制通信协议及报文头部格式。它是整个 RPC 框架在网络传输层进行数据解析和封包的唯一标准。

## 核心文件
* [protocol.h](protocol.h)：定义了协议魔法数、消息类型枚举及固定 16 字节的报文头结构体。
* [protocol.cpp](protocol.cpp)：预留的协议逻辑实现源文件。

## 核心类 / 函数
* `photon::protocol::MAGIC_NUMBER`：协议防伪魔数，值为 `0x5048`（即 ASCII 'P' 和 'H'）。
* `photon::protocol::MsgType`：枚举类，定义了以下报文类型：
  * `REQUEST` (0x01)：服务请求。
  * `RESPONSE` (0x02)：处理结果。
  * `HEARTBEAT` (0x03)：链路探测心跳。
  * `ERROR` (0xFF)：错误反馈。
* `photon::protocol::Header`：报文头部结构体，采用 1 字节紧凑对齐，固定长度为 16 字节，包含 `magic`、`msg_id`、`type`、`flags`、`method_id`、`body_len` 和 `reserved`。

## 工作流程
1. **网络写端封装**：在发送 RPC 请求或响应时，网络发送模块（如 `write_awaiter`）根据请求参数填充 `Header`，随后与序列化后的 `body` 一同写入发送缓冲区。
2. **网络读端解析**：网络接收模块（如 `read_awaiter`）首先读取固定的 16 字节头部，校验 `magic`。若合法，则根据 `body_len` 继续读取对应长度的数据体。
3. **路由分发**：根据 `Header.method_id`，分发器（`dispatcher`）执行 O(1) 的查表定位，将报文路由至对应服务进行处理。

## 与其他模块的关系
* **网络与 Awaiter 模块**：`read_awaiter` 和 `write_awaiter` 直接依赖本模块定义的 `Header` 结构体进行套接字的读写和解析。
* **业务路由分发（Dispatcher）**：分发器通过读取 `Header` 中的 `method_id` 和 `msg_id` 进行分发与匹配。
