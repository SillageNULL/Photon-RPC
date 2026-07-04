/**
 * @file error.h
 * @brief Photon-RPC 异常类型定义。
 * @details 提供 RPC 调用过程中可能抛出的各种异常类型，供业务层捕获和处理。
 * @author Miny
 * @date 2026-07-04
 */

#pragma once

#include <stdexcept>

namespace photon::rpc {

/**
 * @struct RpcTimeoutException
 * @brief RPC 请求超时异常结构体。
 * @details 当 RPC 调用在指定时间内未收到响应时抛出此异常。
 */
struct RpcTimeoutException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

/**
 * @struct RpcDisconnectException
 * @brief RPC 连接断开异常结构体。
 * @details 当底层的网络连接在 RPC 调用尚未完成时发生断开，抛出此异常。
 */
struct RpcDisconnectException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

} /** namespace photon::rpc */
