/**
 * @file config.h
 * @brief Photon-RPC 全局配置与基础常量定义。
 * @details 仅包含标准库头文件和编译期常量，定义了底层控制的枚举类型以及全局控制变量的外部声明。
 * @author Miny
 * @date 2026-07-04
 */

#pragma once

#include <cstdint>
#include <coroutine>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace photon::config {

/**
 * @brief io_uring 队列深度大小。
 */
inline constexpr uint32_t IO_URING_QUEUE_DEPTH = 131072;

/**
 * @brief 默认服务监听端口。
 */
inline constexpr uint16_t DEFAULT_PORT = 8080;

/**
 * @brief TCP 监听队列积压大小 (backlog)。
 */
inline constexpr int TCP_BACKLOG = 8192;

/**
 * @brief 报文体最大长度限制，防止大包导致的内存溢出 (OOM)。
 */
inline constexpr uint32_t MAX_BODY_LEN = 1024 * 1024;

/**
 * @brief CPU L1 数据缓存行大小 (字节)，用于对齐优化防止伪共享。
 */
inline constexpr size_t CACHE_LINE_SIZE = 64;

/**
 * @enum MemoryMode
 * @brief 内存分配模式。
 */
enum class MemoryMode {
    SLAB,   /**< SLAB 内存池分配模式 */
    MALLOC  /**< 标准 malloc/new 分配模式 */
};

/**
 * @enum SendMode
 * @brief 网络发送数据模式。
 */
enum class SendMode {
    WRITEV, /**< 使用 writev 零拷贝散射写 */
    WRITE   /**< 使用普通 memcpy 配合 write */
};

/**
 * @brief 全局内存模式变量，控制系统的内存分配行为。
 */
extern MemoryMode g_memory_mode;

/**
 * @brief 全局发送模式变量，控制套接字的数据发送行为。
 */
extern SendMode g_send_mode;

/**
 * @brief Photon-RPC 版本号字符串。
 */
inline constexpr const char* PHOTON_VERSION = "0.2.1-SQE-OPT-v3";

} /** namespace photon::config */
