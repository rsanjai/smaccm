/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#ifndef __MAVLINK_PARAM_REQUEST_READ_MSG_H__
#define __MAVLINK_PARAM_REQUEST_READ_MSG_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "mavlinkSendModule.h"
#include "mavlink_pack_ivory.h"
struct param_request_read_msg {
    int16_t param_index;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t param_id[16U];
} __attribute__((__packed__));
void mavlink_param_request_read_msg_send(const
                                         struct param_request_read_msg* n_var0,
                                         uint8_t* n_var1, uint8_t n_var2[80U]);
void mavlink_param_request_read_unpack(struct param_request_read_msg* n_var0,
                                       const uint8_t* n_var1);

#ifdef __cplusplus
}
#endif
#endif /* __MAVLINK_PARAM_REQUEST_READ_MSG_H__ */