/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#ifndef __MAVLINK_RAW_PRESSURE_MSG_H__
#define __MAVLINK_RAW_PRESSURE_MSG_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "mavlinkSendModule.h"
#include "mavlink_pack_ivory.h"
struct raw_pressure_msg {
    uint64_t time_usec;
    int16_t press_abs;
    int16_t press_diff1;
    int16_t press_diff2;
    int16_t temperature;
} __attribute__((__packed__));
void mavlink_raw_pressure_msg_send(const struct raw_pressure_msg* n_var0,
                                   uint8_t* n_var1, uint8_t n_var2[80U]);
void mavlink_raw_pressure_unpack(struct raw_pressure_msg* n_var0, const
                                 uint8_t* n_var1);

#ifdef __cplusplus
}
#endif
#endif /* __MAVLINK_RAW_PRESSURE_MSG_H__ */