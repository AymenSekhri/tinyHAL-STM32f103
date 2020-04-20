#include "stm32f103_hal_core.h"
/*

TODO:
- polling for USART_STAT_TC should be replaced by interrupts.

*/

void enablePeripheralClock(int peripheral){
	int configurationBitmask = (1 << LOWERWORD(peripheral));
	switch(UPPERWORD(peripheral)){
		case BUS_AHB:
			RCC->AHBENR |= configurationBitmask;
			break;
		case BUS_APB1:
			RCC->APB1ENR |= configurationBitmask;
			break;
		case BUS_APB2:
			RCC->APB2ENR |= configurationBitmask;
			break;
	}
}

void disablePeripheralClock(int peripheral){
	int configurationBitmask = ~(1 << LOWERWORD(peripheral));
	switch(UPPERWORD(peripheral)){
		case BUS_AHB:
			RCC->AHBENR &= configurationBitmask;
			break;
		case BUS_APB1:
			RCC->APB1ENR &= configurationBitmask;
			break;
		case BUS_APB2:
			RCC->APB2ENR &= configurationBitmask;
			break;
	}
}

void configureGPIO(int port,int pin,int mode,int configuration){
	bool isLowerPort = pin<8?true:false;
	int configurationBitmask = 0;
	if(isLowerPort){
		configurationBitmask = mode<<(pin*2);
	}else{
		configurationBitmask = mode<<((pin-8)*2);
	}
	switch(port){
		case Peripheral_GPIOA:
			if(isLowerPort)
				GPIOA->CRL = (GPIOA->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOA->CRH = (GPIOA->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOB:
			if(isLowerPort)
				GPIOB->CRL = (GPIOB->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOB->CRH = (GPIOB->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOC:
			if(isLowerPort){
				GPIOC->CRL = (GPIOC->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			}else
				GPIOC->CRH = (GPIOC->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOD:
			if(isLowerPort)
				GPIOD->CRL = (GPIOD->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOD->CRH = (GPIOD->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOE:
			if(isLowerPort)
				GPIOE->CRL = (GPIOE->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOE->CRH = (GPIOE->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOF:
			if(isLowerPort)
				GPIOF->CRL = (GPIOF->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOF->CRH = (GPIOF->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		case Peripheral_GPIOG:
			if(isLowerPort)
				GPIOG->CRL = (GPIOG->CRL & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			else
				GPIOG->CRH = (GPIOG->CRH & ~(0xF << (pin%8)*4) ) |  (mode | configuration << 2) << (pin%8)*4;
			break;
		
	}
}



