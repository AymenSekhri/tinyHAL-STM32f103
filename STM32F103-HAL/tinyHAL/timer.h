#include "stm32f103_hal_core.h"
#include "interrupts.h"

#define TIMER2_CONF_CH1 	0
#define TIMER2_CONF_CH2 	0
#define TIMER2_CONF_CH3 	0
#define TIMER2_CONF_CH4 	0

#define TIMER_CONF_CR1_CEN 			(1 << 0)

#define TIMER_CONF_DIER_UIE 		(1 << 0)

#define TIMER_STAT_UIF 				(1 << 0)


static void delayMilliseconds(int milliseconds);

void initiateTimer(int timerID);
void destroyTimer(int timerID);
void delay(int milliseconds);
void setupTasklet(int timerID,int period ,void* handler);
void destroyTasklet(int timerID);