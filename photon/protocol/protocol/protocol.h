/**
 * @file protocol.h
 * @brief Photon-RPC 二进制通信协议与报文格式定义。
 * @details 协议采用零拷贝友好的紧凑布局，Header 固定 16 字节。
 *          通过 method_id 支持 O(1) 业务路由，flags 预留扩展位。
 * @author Miny
 * @date 2026-07-04
 */

#pragma once

#include <cstdint>

namespace photon::protocol {

/**
 * @brief 协议防伪魔数 'P' 'H'。
 */
inline constexpr uint16_t MAGIC_NUMBER = 0x5048;

/**
 * @enum MsgType
 * @brief 报文行为类型枚举。
 */
enum class MsgType : uint8_t {
    REQUEST   = 0x01, /**< 服务请求报文 */
    RESPONSE  = 0x02, /**< 处理结果响应报文 */
    HEARTBEAT = 0x03, /**< 链路探测心跳报文 */
    ERROR     = 0xFF  /**< 错误反馈报文 */
};

/**
 * @struct Header
 * @brief 16 字节固定长度消息头 (1 字节对齐)。
 */
#pragma pack(push, 1)
struct Header {
    /**
     * @brief 魔数校验，固定为 MAGIC_NUMBER (0x5048)，用于检验报文合法性。
     */
    uint16_t magic     = MAGIC_NUMBER;

    /**
     * @brief 会话唯一标识 ID，用于请求与响应的配对。
     */
    uint32_t msg_id    = 0;

    /**
     * @brief 报文行为类型，参见 MsgType。
     */
    MsgType  type      = MsgType::REQUEST;

    /**
     * @brief 预留标志位，用于未来协议扩展。
     */
    uint8_t  flags     = 0;

    /**
     * @brief 业务路由键，用于 O(1) 业务处理路由分发。
     */
    uint16_t method_id = 0;

    /**
     * @brief 报文体 (Body) 的字节长度。
     */
    uint32_t body_len  = 0;

    /**
     * @brief 协议保留字段，用于后续结构对齐或扩展。
     */
    uint16_t reserved  = 0;
};
#pragma pack(pop)

} /** namespace photon::protocol */
