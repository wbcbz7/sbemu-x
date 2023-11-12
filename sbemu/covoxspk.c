#include "platform.h"
#include "dpmi/dbgutil.h"
#include "sbemu.h"
#include <string.h>
#include "covoxspk.h"
#include "dirpcm.h"

// Covox / PC-Speaker emulation code

enum {
    SPEAKER_ENABLED     =  (1 << 0),
    COVOX_ENABLED       =  (1 << 0), 
    COVOX_STEREO_ON_1   =  (1 << 1),

    COVOX_OUT_L = (1 << 0),
    COVOX_OUT_R = (1 << 1),
};

struct covoxspk_state_t {
    struct {
        // flags
        uint8_t flags;

        // shadow registers
        uint8_t data, control;

        // channel output mask
        uint8_t chanmask;
    } covox;

    struct {
        // flags
        uint8_t flags;
    } spk;
};

static struct covoxspk_state_t covoxspk;

// ------------------------
// covox trap procedures

uint8_t covox_data_write(uint16_t port, uint8_t value) {
    covoxspk.covox.data = value;
    if (covoxspk.covox.flags & COVOX_STEREO_ON_1) {
        // TODO
    } else {
        // write mono sample
        direct_pcm_push_mono_u8(value);
    }

    return value;
}
uint8_t covox_data_read (uint16_t port) {
    return covoxspk.covox.data;
}

uint8_t covox_status_write(uint16_t port, uint8_t value) {
    // unwritable
    return value;
}
uint8_t covox_status_read (uint16_t port) {
    uint8_t rtn = 0;

    // stereo-on-1 detect
    if (covoxspk.covox.flags & COVOX_STEREO_ON_1) rtn |= (covoxspk.covox.data ^ 0x80) & 0x80; 
    return rtn;
}

uint8_t covox_control_write(uint16_t port, uint8_t value) {
    covoxspk.covox.control = value;
    if (covoxspk.covox.flags & COVOX_STEREO_ON_1) {
        // TODO
    }
    return value;
}
uint8_t covox_control_read (uint16_t port) {
    return covoxspk.covox.control;
}

// ------------------------

int covoxspk_init(int covox, int stereo_on_1, int pcspeaker) {
    memset(&covoxspk, 0, sizeof(covoxspk));

    covoxspk.covox.flags = ((!!covox ? COVOX_ENABLED : 0) | (!!stereo_on_1 ? COVOX_STEREO_ON_1 : 0));
    covoxspk.spk.flags = (!!pcspeaker ? SPEAKER_ENABLED : 0);
    covoxspk.covox.chanmask = COVOX_OUT_L | COVOX_OUT_R;

    return 1;   // ok
}

int covoxspk_done() {
    return 1;   // ok
}
