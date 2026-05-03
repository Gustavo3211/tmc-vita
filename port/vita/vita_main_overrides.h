#pragma once

/*
 * Vita paths and overrides
 */

/* PSVITA Paths */
#define VITA_DATA_PATH "ux0:data/tmc"
#define VITA_ROM_PATH "ux0:data/tmc/baserom.gba"
#define VITA_GAPS_PATH "ux0:data/tmc/rom_gaps.bin"
#define VITA_ROMDATA_DIR "ux0:data/tmc/rom_data"
#define VITA_SAVE_PATH "ux0:data/tmc/tmc.sav"

/* Force __vita__ define */
#ifndef __vita__
#define __vita__ 1
#endif
