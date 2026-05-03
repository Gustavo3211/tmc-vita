/* Audio stubs for Vita */

#include "global.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#if defined(__vita__) && defined(VITA_PERSISTENT_LOGS)
#include <reent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

__attribute__((constructor))
static void vita_log_init(void) {
    /* Create folders */
    mkdir("ux0:data", 0777);
    mkdir("ux0:data/tmc", 0777);

    /* Write test */
    FILE* test = fopen("ux0:data/tmc/tmc_log.txt", "w");
    if (test) {
        fprintf(test, "--- Log Init OK ---\n");
        fclose(test);
    }

    /* Redirect log */
    freopen("ux0:data/tmc/tmc_log.txt", "a", stdout);
    freopen("ux0:data/tmc/tmc_log.txt", "a", stderr);
    
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    
    printf("--- TMC Vita Log Start (APPEND) ---\n");
}
#endif

/* port_audio.h */
bool Port_Audio_Init(void) { return true; }
void Port_Audio_Shutdown(void) {}
void Port_Audio_Reset(void) {}
void Port_Audio_OnFifoWrite(uint32_t addr, uint32_t value) {
    (void)addr;
    (void)value;
}

/* port_m4a_backend.h */
struct SongHeader;

bool Port_M4A_Backend_Init(uint32_t sampleRate) {
    (void)sampleRate;
    return true;
}
void Port_M4A_Backend_Shutdown(void) {}
void Port_M4A_Backend_Reset(void) {}
void Port_M4A_Backend_SoundInit(uint32_t soundMode) { (void)soundMode; }
void Port_M4A_Backend_SetSoundMode(uint32_t soundMode) { (void)soundMode; }
void Port_M4A_Backend_SetVSyncEnabled(bool enabled) { (void)enabled; }
bool Port_M4A_Backend_StartSongById(uint8_t playerIndex, uint16_t songId) {
    (void)playerIndex;
    (void)songId;
    return true;
}
void Port_M4A_Backend_StartSong(uint8_t playerIndex, const struct SongHeader* songHeader) {
    (void)playerIndex;
    (void)songHeader;
}
void Port_M4A_Backend_StopPlayer(uint8_t playerIndex) { (void)playerIndex; }
void Port_M4A_Backend_ContinuePlayer(uint8_t playerIndex) { (void)playerIndex; }
void Port_M4A_Backend_SetTrackVolume(uint8_t playerIndex, uint16_t trackBits, uint16_t volume) {
    (void)playerIndex;
    (void)trackBits;
    (void)volume;
}
void Port_M4A_Backend_SetTrackPan(uint8_t playerIndex, uint16_t trackBits, int8_t pan) {
    (void)playerIndex;
    (void)trackBits;
    (void)pan;
}
void Port_M4A_Backend_Render(int16_t* outSamples, uint32_t frameCount, bool mute) {
    (void)outSamples;
    (void)frameCount;
    (void)mute;
}

/* ---- Update Check Stub ---- */
void Port_CheckForUpdates(void) {}
