/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#ifndef __MAVLINK_GLOBAL_VISION_POSITION_ESTIMATE_MSG_H__
#define __MAVLINK_GLOBAL_VISION_POSITION_ESTIMATE_MSG_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "mavlinkSendModule.h"
#include "mavlink_pack_ivory.h"
struct global_vision_position_estimate_msg {
    uint64_t usec;
    float x;
    float y;
    float z;
    float roll;
    float pitch;
    float yaw;
} __attribute__((__packed__));
void mavlink_global_vision_position_estimate_msg_send(const
                                                      struct global_vision_position_estimate_msg* n_var0,
                                                      uint8_t* n_var1,
                                                      uint8_t n_var2[80U]);
void mavlink_global_vision_position_estimate_unpack(struct global_vision_position_estimate_msg* n_var0,
                                                    const uint8_t* n_var1);

#ifdef __cplusplus
}
#endif
#endif /* __MAVLINK_GLOBAL_VISION_POSITION_ESTIMATE_MSG_H__ */