/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.0
 */
#ifndef __RADIO_STAT_TYPE_H__
#define __RADIO_STAT_TYPE_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
struct radio_stat {
    bool sik;
    uint8_t loc_rssi;
    uint8_t loc_noise;
    uint16_t loc_rxctr;
    uint8_t rem_rssi;
    uint8_t rem_noise;
    uint16_t rem_rxctr;
    uint16_t tx_err;
    uint16_t rx_err;
    uint16_t tx_ovf;
    uint16_t rx_ovf;
    uint16_t ecc_errs;
    uint16_t ecc_pkts;
} __attribute__((__packed__));

#ifdef __cplusplus
}
#endif
#endif /* __RADIO_STAT_TYPE_H__ */