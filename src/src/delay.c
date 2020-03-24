#include "delay.h"
 
uint32_t usTicks;
 
void SysTick_Handler()
{
    if (usTicks != 0)usTicks--;
}
 
void initDelay()
{
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000000);
}
 
void Delay(uint32_t miliseconds)
{
    while (miliseconds--) 
		{
			usTicks = 1000;
			while (usTicks);
		}
}
