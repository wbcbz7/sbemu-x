#include <stdlib.h>
#include <sbemucfg.h>
#include "dirpcm.h"

struct direct_pcm_state_t {
    uint8_t  *buffer;
    uint32_t size;
    uint32_t start;
    uint32_t cursor;
};

static struct direct_pcm_state_t direct_pcm;

int direct_pcm_init(uint32_t samples) {
    if (!direct_pcm_done()) return 0;

    direct_pcm.buffer = (uint8_t*)malloc(samples * sizeof(uint8_t));
    if (direct_pcm.buffer == NULL) return 0;
    direct_pcm.size   = samples;
    direct_pcm.start  = 0;
    direct_pcm.cursor = 0;

    return 1;
}

void direct_pcm_clear() {
    direct_pcm.cursor = direct_pcm.start;
}

int direct_pcm_done() {
    if (direct_pcm.buffer != NULL) {
        free(direct_pcm.buffer);
        direct_pcm.buffer == NULL;
        direct_pcm.size   = 0;
        direct_pcm.start  = 0;
        direct_pcm.cursor = 0;
    }
    return 1;
}

uint32_t direct_pcm_get_size() {
    return (direct_pcm.cursor - direct_pcm.start);
}

uint8_t* direct_pcm_get_data() {
    return direct_pcm.buffer;
}

// TODO: apply -3db for mono samples?
// -----------------------
void direct_pcm_push_mono_u8(uint8_t sample) {
    if ((direct_pcm.buffer == NULL) || (direct_pcm.cursor >= direct_pcm.size)) return;
    *(direct_pcm.buffer + direct_pcm.cursor + 0) = sample;
    direct_pcm.cursor += 1;
}

void direct_pcm_push_stereo_u8(uint8_t left, uint8_t right) {
}

void direct_pcm_push_mono_i16(int16_t sample) {
}

void direct_pcm_push_stereo_u16(int16_t left, int16_t right) {
}
