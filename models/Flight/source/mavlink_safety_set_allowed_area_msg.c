/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#include "mavlink_safety_set_allowed_area_msg.h"

void mavlink_safety_set_allowed_area_msg_send(const
                                              struct safety_set_allowed_area_msg* n_var0,
                                              uint8_t* n_var1,
                                              uint8_t n_var2[80U])
{
    uint8_t n_local0[27U] = {};
    uint8_t* n_ref1 = n_local0;
    float n_deref2 = n_var0->p1x;
    
    mavlink_pack_float((uint8_t*) n_ref1, 0U, n_deref2);
    
    float n_deref3 = n_var0->p1y;
    
    mavlink_pack_float((uint8_t*) n_ref1, 4U, n_deref3);
    
    float n_deref4 = n_var0->p1z;
    
    mavlink_pack_float((uint8_t*) n_ref1, 8U, n_deref4);
    
    float n_deref5 = n_var0->p2x;
    
    mavlink_pack_float((uint8_t*) n_ref1, 12U, n_deref5);
    
    float n_deref6 = n_var0->p2y;
    
    mavlink_pack_float((uint8_t*) n_ref1, 16U, n_deref6);
    
    float n_deref7 = n_var0->p2z;
    
    mavlink_pack_float((uint8_t*) n_ref1, 20U, n_deref7);
    
    uint8_t n_deref8 = n_var0->target_system;
    
    mavlink_pack_uint8_t((uint8_t*) n_ref1, 24U, n_deref8);
    
    uint8_t n_deref9 = n_var0->target_component;
    
    mavlink_pack_uint8_t((uint8_t*) n_ref1, 25U, n_deref9);
    
    uint8_t n_deref10 = n_var0->frame;
    
    mavlink_pack_uint8_t((uint8_t*) n_ref1, 26U, n_deref10);
    for (int32_t n_ix11 = 0; n_ix11 <= 26; n_ix11++) {
        ASSERTS(n_ix11 > 0 && 2147483647 - n_ix11 >= 6 || n_ix11 <= 0);
        if (n_ix11 + 6 >= 80) { } else {
            uint8_t n_deref12 = n_ref1[n_ix11];
            
            ASSERTS(n_ix11 > 0 && 2147483641 >= n_ix11 || n_ix11 <= 0);
            ASSERTS(0 <= 6 + n_ix11 && 6 + n_ix11 < 80);
            *&n_var2[(6 + n_ix11) % 80] = n_deref12;
        }
    }
    mavlinkSendWithWriter(54U, 15U, 27U, n_var1, n_var2);
    for (int32_t n_ix13 = 0; n_ix13 <= 44; n_ix13++) {
        ASSERTS(n_ix13 > 0 && 2147483647 - n_ix13 >= 35 || n_ix13 <= 0);
        ASSERTS(0 <= n_ix13 + 35 && n_ix13 + 35 < 80);
        *&n_var2[(n_ix13 + 35) % 80] = 0U;
    }
    return;
}

void mavlink_safety_set_allowed_area_unpack(struct safety_set_allowed_area_msg* n_var0,
                                            const uint8_t* n_var1)
{
    float n_r0 = mavlink_unpack_float(n_var1, 0U);
    
    *&n_var0->p1x = n_r0;
    
    float n_r1 = mavlink_unpack_float(n_var1, 4U);
    
    *&n_var0->p1y = n_r1;
    
    float n_r2 = mavlink_unpack_float(n_var1, 8U);
    
    *&n_var0->p1z = n_r2;
    
    float n_r3 = mavlink_unpack_float(n_var1, 12U);
    
    *&n_var0->p2x = n_r3;
    
    float n_r4 = mavlink_unpack_float(n_var1, 16U);
    
    *&n_var0->p2y = n_r4;
    
    float n_r5 = mavlink_unpack_float(n_var1, 20U);
    
    *&n_var0->p2z = n_r5;
    
    uint8_t n_r6 = mavlink_unpack_uint8_t(n_var1, 24U);
    
    *&n_var0->target_system = n_r6;
    
    uint8_t n_r7 = mavlink_unpack_uint8_t(n_var1, 25U);
    
    *&n_var0->target_component = n_r7;
    
    uint8_t n_r8 = mavlink_unpack_uint8_t(n_var1, 26U);
    
    *&n_var0->frame = n_r8;
}