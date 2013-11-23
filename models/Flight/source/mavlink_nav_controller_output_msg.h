/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#ifndef __MAVLINK_NAV_CONTROLLER_OUTPUT_MSG_H__
#define __MAVLINK_NAV_CONTROLLER_OUTPUT_MSG_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "mavlinkSendModule.h"
#include "mavlink_pack_ivory.h"
struct nav_controller_output_msg {
    float nav_roll;
    float nav_pitch;
    float alt_error;
    float aspd_error;
    float xtrack_error;
    int16_t nav_bearing;
    int16_t target_bearing;
    uint16_t wp_dist;
} __attribute__((__packed__));
void mavlink_nav_controller_output_msg_send(const
                                            struct nav_controller_output_msg* n_var0,
                                            uint8_t* n_var1,
                                            uint8_t n_var2[80U]);
void mavlink_nav_controller_output_unpack(struct nav_controller_output_msg* n_var0,
                                          const uint8_t* n_var1);

#ifdef __cplusplus
}
#endif
#endif /* __MAVLINK_NAV_CONTROLLER_OUTPUT_MSG_H__ */