#include "SoundManager.h"

inline void speaker_init() {
    RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER4_0;
}
inline void speaker_reset(void) {
    GPIOA->ODR &= GPIO_ODR_0;
}
extern inline void my_delay(volatile uint32_t count)
{
	while(count>0)
	{
		count--;
		__NOP();
	}
}
inline void speaker_squeak_hz(double sec, double hz) {
    uint32_t t = SECOND * sec;
    uint32_t T = (double)SECOND / hz;// * 7.19;
    uint32_t loops = (double)t / T;
    T /= 2;
    while(loops--) {
        GPIOA->ODR |= GPIO_ODR_4;
     my_delay(T);
     GPIOA->ODR &= GPIO_ODR_0;
     my_delay(T);
    }
}

inline void sound_correct_key(void)
{
	speaker_squeak_hz(0.001,10000);
	speaker_squeak_hz(0.001,1200);
	speaker_squeak_hz(0.001,140000);
}
inline void sound_uncorrect_key(void)
{
	speaker_squeak_hz(0.004,1000);
}
inline void sound_test(void)
{
	
		speaker_squeak_hz(0.1,100);
		speaker_squeak_hz(0.1,1000);
		speaker_squeak_hz(0.1,1000);
	
}