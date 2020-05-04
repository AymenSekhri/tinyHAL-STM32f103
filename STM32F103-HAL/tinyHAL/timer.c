#include "timer.h"
void initiateTimer(int timerID){
	enablePeripheralClock(timerID);
}

void destroyTimer(int timerID){
	disablePeripheralClock(timerID);
}

void delay(int milliseconds){// Uses Timer2 in 72MHz
	int iterationsNumber = milliseconds / 1000 + (milliseconds%1000 != 0);
	for(int i=0; i<iterationsNumber; i++){
		delayMilliseconds((( i == (iterationsNumber-1) )? (milliseconds % 1000) : 1000 ));
	}
}
void delayMilliseconds(int milliseconds // max is 1ms
						){
		TIM2->PSC = 7200 - 1;
		TIM2->ARR = 10 * milliseconds - 1;
		TIM2->CNT = 0;
		TIM2->CR1 = TIMER_CONF_CR1_CEN;
		while(!(TIM2->SR & TIMER_STAT_UIF));
		TIM2->SR &= ~TIMER_STAT_UIF;
	
}