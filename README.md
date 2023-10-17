# SBEMU-X

Emulate Sound Blaster and OPL3 in pure DOS using modern
PCI-based (onboard and add-in card) sound cards.

## Changes compared to sbemu

This is obviously a friendly fork of [SBEMU](https://github.com/crazii/SBEMU)
to allow for cross-compilation, additional driver support,
continuous integration, bug fixes, etc..

Ideally, we'd like to get these changes integrated upstream
eventually.

For now, this fork provides additional support:

* Build support under Linux, Windows, macOS (DJGPP cross-compilation)
* Nicer text-mode user interface
* Additional sound card support
  * SIS 7012
  * CMI 8338 / 8738 (untested)

## Supported sound cards

Source code from [MPXPlay](https://mpxplay.sourceforge.net/)
is used to support the following sound cards/chips.

Enabled and working:

 * `sc_ich`: Intel ICH / nForce / SIS 7012
 * `sc_inthd`: Intel High Definition Audio
 * `sc_via82`: VIA VT82C686, VT8233
 * `sc_sbliv`: SB Live! / Audigy
 * `sc_sbl24`: SB Audigy LS (CA0106)

Support compiled-in, but untested:

 * `sc_es1371`: Ensoniq ES1371/1373
 * `sc_cmi`: C-Media CMI8338/8738

Cards with known issue:

 * AC97 with AD1980 SoundMAX codec (muted audio, WIP)

Source code exists, but "doesn't work yet":

 * `sc_sbxfi`: Creative X-Fi EMU20KX

Source code exists, but not sure if viable:

 * `sc_wss`: Windows Sound System compatible cards
 * `sc_cmi`: CMI 8338/8738 (PCI) cards
 * `sc_ess`: ESS card handling
 * `sc_gus`: Gravis UltraSound
 * `sc_midas`: MIDAS library handling

## Emulated modes

 * 8-bit and 16-bit DMA (mono, stereo, high-speed)
 * Sound Blaster 1.0, 2.0, Pro, 16
 * OPL3 FM via [DOSBox' OPL3 FM implementation](https://www.dosbox.com/)

## Requirements

 * [HDPMI32i](https://github.com/crazii/HX) (HDPMI with IOPL0)
 * Optional, for real-mode game support (I/O trapping):
   * [JEMM](https://github.com/Baron-von-Riedesel/Jemm) with QPIEMU.DLL loaded
   * or [QEMM](https://en.wikipedia.org/wiki/QEMM), commercial software

For memory management, use either:

 * `JEMMEX` only: Provides both HIMEM + EMM
 * `HIMEMX` and `JEMM386`: Separate HIMEM + EMM

In both cases, use `JLOAD` (from the Jemm distribution)
to load `QPIEMU.DLL` before starting `SBEMU`,
so that real-mode support is enabled. If you don't load
JEMM+QPIEMU (or QEMM), only protected mode applications
will be supported.
