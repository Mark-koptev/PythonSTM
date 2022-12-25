#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#define SECOND 72000000
#include "main.h"

extern inline void my_delay(volatile uint32_t count);
extern inline void delay_sec(double sec);
void speaker_init();
void speaker_squeak_hz(double sec, double hz);
void sound_correct_key(void);
void sound_test(void);
void speaker_reset(void);

#endif
