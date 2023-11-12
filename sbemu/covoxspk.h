#ifndef _COVOXSPK_H
#define _COVOXSPK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// port handlers
uint8_t covox_data_write(uint16_t port, uint8_t value);
uint8_t covox_data_read (uint16_t port);

uint8_t covox_status_write(uint16_t port, uint8_t value);
uint8_t covox_status_read (uint16_t port);

uint8_t covox_control_write(uint16_t port, uint8_t value);
uint8_t covox_control_read (uint16_t port);

uint8_t pcspeaker_control_write(uint16_t port, uint8_t value);
uint8_t pcspeaker_control_read (uint16_t port);

uint8_t pcspeaker_timer2_write(uint16_t port, uint8_t value);
uint8_t pcspeaker_timer2_read (uint16_t port);

uint8_t pcspeaker_timerctrl_write(uint16_t port, uint8_t value);
uint8_t pcspeaker_timerctrl_read (uint16_t port);


// ------------------------

// init covox/speaker emulation
int covoxspk_init(int covox, int stereo_on_1, int pcspeaker);

// close it
int covoxspk_done();


#ifdef __cplusplus
}
#endif

#endif