/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RADIO_H_
#define _RADIO_H_

/* Ramp up times from OPS.
 */
#define RADIO_TX_READY_DELAY_US 140
#define RADIO_RX_READY_DELAY_US	138

/* Chain delays from OPS.
 * nRF51: Tx= 1us, Rx= 3us;
 * nRF52: Tx= 0.6us, Rx= 9.4us.
 */
#define RADIO_TX_CHAIN_DELAY_US 1
#define RADIO_RX_CHAIN_DELAY_US	10

typedef void (*radio_isr_fp) (void);

void isr_radio(void);
void radio_isr_set(radio_isr_fp fp_radio_isr);

void radio_reset(void);
void radio_phy_set(u8_t phy);
void radio_tx_power_set(u32_t power);
void radio_freq_chan_set(u32_t chan);
void radio_whiten_iv_set(u32_t iv);
void radio_aa_set(u8_t *aa);
void radio_pkt_configure(u8_t preamble16, u8_t bits_len, u8_t max_len);
void radio_pkt_rx_set(void *rx_packet);
void radio_pkt_tx_set(void *tx_packet);
void radio_rx_enable(void);
void radio_tx_enable(void);
void radio_disable(void);

void radio_status_reset(void);
u32_t radio_is_ready(void);
u32_t radio_is_done(void);
u32_t radio_has_disabled(void);
u32_t radio_is_idle(void);

void radio_crc_configure(u32_t polynomial, u32_t iv);
u32_t radio_crc_is_valid(void);

void *radio_pkt_empty_get(void);
void *radio_pkt_scratch_get(void);

void radio_switch_complete_and_rx(void);
void radio_switch_complete_and_tx(void);
void radio_switch_complete_and_disable(void);

void radio_rssi_measure(void);
u32_t radio_rssi_get(void);
void radio_rssi_status_reset(void);
u32_t radio_rssi_is_ready(void);

void radio_filter_configure(u8_t bitmask_enable, u8_t bitmask_addr_type,
			    u8_t *bdaddr);
void radio_filter_disable(void);
void radio_filter_status_reset(void);
u32_t radio_filter_has_match(void);

void radio_bc_configure(u32_t n);
void radio_bc_status_reset(void);
u32_t radio_bc_has_match(void);

void radio_tmr_status_reset(void);
void radio_tmr_tifs_set(u32_t tifs);
u32_t radio_tmr_start(u8_t trx, u32_t ticks_start, u32_t remainder);
void radio_tmr_stop(void);
void radio_tmr_hcto_configure(u32_t hcto);
void radio_tmr_aa_capture(void);
u32_t radio_tmr_aa_get(void);
void radio_tmr_end_capture(void);
u32_t radio_tmr_end_get(void);
void radio_tmr_sample(void);
u32_t radio_tmr_sample_get(void);

void *radio_ccm_rx_pkt_set(struct ccm *ccm, void *pkt);
void *radio_ccm_tx_pkt_set(struct ccm *ccm, void *pkt);
u32_t radio_ccm_is_done(void);
u32_t radio_ccm_mic_is_valid(void);

void radio_ar_configure(u32_t nirk, void *irk);
u32_t radio_ar_match_get(void);
void radio_ar_status_reset(void);
u32_t radio_ar_has_match(void);

#endif
