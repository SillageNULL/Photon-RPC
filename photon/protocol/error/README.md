# Error 模块

## 模块职责
Error 模块专门定义了 Photon-RPC 框架在网络通信和远程调用过程中可能触发的各类系统级异常，提供了标准化的错误传递和捕获机制。

## 核心文件
* [error.h](error.h)：定义了 RPC 请求超时及连接断开等异常结构体。
* [error.cpp](error.cpp)：预留的错误处理实现源文件。

## 核心类 / 函数
* `photon::rpc::RpcTimeoutException`：当 RPC 调用在规定的超时时间内未能收到对端响应时抛出。
* `photon::rpc::RpcDisconnectException`：当底层套接字意外关闭或网络断开导致当前未完成的 RPC 呼叫被迫终止时抛出。

## 工作流程
1. **异常触发**：当 RPC 请求在发送后，在定时器线程或 io_uring 事件循环中检测到请求超时，或者在套接字读写时发现对端已关闭连接，通道层（`rpc_channel`）会标识当前的挂起条目状态。
2. **异常抛出**：协程在被唤醒并在 `await_resume()` 中恢复执行时，会检查挂起条目的返回状态。若为异常状态，则在协程内部抛出对应的 `RpcTimeoutException` 或 `RpcDisconnectException`。
3. **异常捕获**：上层业务代码（如 `client_app` 中的服务调用者）通过普通的 `try-catch` 块捕获这些异常，并执行相应的降级或重试逻辑。

## 与其他模块的关系
* **RPC 通道模块（Channel）**：`rpc_channel` 模块是本模块异常的直接抛出者，通过协程的 `await_resume()` 将网络侧和时间侧的错误转化为标准 C++ 异常向上传播。
* **业务应用（App/Client）**：客户端应用程序直接捕获该模块的异常并进行业务容错处理。
