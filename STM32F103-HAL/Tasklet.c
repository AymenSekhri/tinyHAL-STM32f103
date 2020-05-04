/* 
* Description:
*	Toggle LED at C13 in the ISR of a timer interrupt each 1s.
*
*/
#include "tinyHAL/stm32f103_hal.h"

void myISR(void);
int main(){
	enablePeripheralClock(Peripheral_GPIOC);
	configureGPIO(Peripheral_GPIOC, 13, GPIO_MODE_OUT_50MHZ, GPIO_CONF_OUT_PUSHPULL);
	
	initiateTimer(Peripheral_TIM3);
	setupTasklet(Peripheral_TIM3, 1000, myISR);
	
	while(1);
}

void myISR(void){
	toggleGPIOBit(Peripheral_GPIOC, 13);
}