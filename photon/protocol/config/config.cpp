/**
 * @file config.cpp
 * @brief 全局变量的定义与初始化。
 * @author Miny
 * @date 2026-07-04
 */

#include "config.h"

namespace photon::config {

/**
 * @brief 全局内存模式定义。默认使用 SLAB 内存池模式。
 */
MemoryMode g_memory_mode = MemoryMode::SLAB;

/**
 * @brief 全局数据发送模式定义。默认使用 WRITEV 零拷贝发送。
 */
SendMode g_send_mode = SendMode::WRITEV;

} /** namespace photon::config */
