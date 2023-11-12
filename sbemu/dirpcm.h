#ifndef _DIRPCM_H
#define _DIRPCM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// init direct PCM buffer
int direct_pcm_init(uint32_t samples);

// deinit it
int direct_pcm_done();

// push samples
void direct_pcm_push_mono_u8(uint8_t sample);
void direct_pcm_push_stereo_u8(uint8_t left, uint8_t right);

void direct_pcm_push_mono_i16(int16_t sample);
void direct_pcm_push_stereo_i16(int16_t left, int16_t right);

// clear buffer
void direct_pcm_clear();

// get buffer size in sample frames 
uint32_t direct_pcm_get_size();

// get buffer data
uint8_t* direct_pcm_get_data();

#ifdef __cplusplus
}
#endif

#endif
