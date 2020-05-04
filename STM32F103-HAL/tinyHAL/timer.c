#include "timer.h"
void* TIM_ISR[5] = {0};

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

void setupTasklet(int timerID,int period ,void* handler){
	disableInterrupts();
	TIM_TypeDef* TIM;
	switch(timerID){
		case Peripheral_TIM2:
			TIM = TIM2;
			TIM_ISR[2] = handler;
			enableIRQ(TIM2_IRQn, 1);
			break;
		case Peripheral_TIM3:
			TIM = TIM3;
			TIM_ISR[3] = handler;
			enableIRQ(TIM3_IRQn, 1);
			break;
		case Peripheral_TIM4:
			TIM = TIM4;
			TIM_ISR[4] = handler;
			enableIRQ(TIM4_IRQn, 1);
			break;
		default:
			return;
	}
	TIM->PSC = 7200 - 1;
	TIM->ARR = 10 * period - 1;
	TIM->DIER |= TIMER_CONF_DIER_UIE;
	TIM->CR1 = TIMER_CONF_CR1_CEN;
	enableInterrupts();
}

void destroyTasklet(int timerID){
	disableInterrupts();
	TIM_TypeDef* TIM;
	switch(timerID){
		case Peripheral_TIM2:
			TIM = TIM2;
			TIM_ISR[1] = 0;
			disableIRQ(TIM2_IRQn);
			break;
		case Peripheral_TIM3:
			TIM = TIM3;
			TIM_ISR[2] = 0;
			disableIRQ(TIM3_IRQn);
			break;
		case Peripheral_TIM4:
			TIM = TIM4;
			TIM_ISR[3] = 0;
			disableIRQ(TIM4_IRQn);
			break;
		default:
			return;
	}
	TIM->CR1 = 0;
	enableInterrupts();
}
//Timers IRQ Callbacks
void TIM2_IRQHandler(void){
	if(TIM_ISR[2]){
		void (*ISR)(void);
		ISR = TIM_ISR[2];
		ISR();
		TIM2->SR &= ~TIMER_STAT_UIF;
	}
}

void TIM3_IRQHandler(void){
	if(TIM_ISR[3]){
		void (*ISR)(void);
		ISR = TIM_ISR[3];
		ISR();
		TIM3->SR &= ~TIMER_STAT_UIF;
	}
}

void TIM4_IRQHandler(void){
	if(TIM_ISR[4]){
		void (*ISR)(void);
		ISR = TIM_ISR[4];
		ISR();
		TIM4->SR &= ~TIMER_STAT_UIF;
	}
}

