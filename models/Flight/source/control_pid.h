/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#ifndef __CONTROL_PID_H__
#define __CONTROL_PID_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
struct PIDState {
    float pid_iState;
    float pid_dState;
    uint8_t pid_reset;
} __attribute__((__packed__));
struct PIDConfig {
    float pid_pGain;
    float pid_iGain;
    float pid_dGain;
    float pid_iMin;
    float pid_iMax;
} __attribute__((__packed__));
float fconstrain(float n_var0, float n_var1, float n_var2);
float pid_update(struct PIDState* n_var0, const struct PIDConfig* n_var1,
                 float n_var2, float n_var3);

#ifdef __cplusplus
}
#endif
#endif /* __CONTROL_PID_H__ */