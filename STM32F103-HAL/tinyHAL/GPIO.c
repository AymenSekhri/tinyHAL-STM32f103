#include "GPIO.h"

void setGPIOBit(int port,int pin,bool value){
	if(value)
		setGPIOBitHigh(port,pin);
	else
		setGPIOBitLow (port,pin);
}

void setGPIOBitLow(int port,int pin){
	switch(port){
		case Peripheral_GPIOA:
			GPIOA->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOB:
			GPIOB->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOC:
			GPIOC->ODR &= ~(1 << pin);
		case Peripheral_GPIOD:
			GPIOD->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOE:
			GPIOE->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOF:
			GPIOF->ODR &= ~(1 << pin);
			break;
		case Peripheral_GPIOG:
			GPIOG->ODR &= ~(1 << pin);
			break;
	}
}
void setGPIOBitHigh(int port,int pin){
	switch(port){
		case Peripheral_GPIOA:
			GPIOA->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOB:
			GPIOB->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOC:
			GPIOC->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOD:
			GPIOD->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOE:
			GPIOE->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOF:
			GPIOF->ODR |=  (1 << pin);
			break;
		case Peripheral_GPIOG:
			GPIOG->ODR |=  (1 << pin);
			break;
		default:
			break;
	}
}

bool readGPIOBit(int port,int pin){
	switch(port){
		case Peripheral_GPIOA:
			return (GPIOA->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOB:
			return (GPIOB->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOC:
			return (GPIOC->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOD:
			return (GPIOD->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOE:
			return (GPIOE->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOF:
			return (GPIOF->IDR & (1 << pin))==0? 0:1;
		case Peripheral_GPIOG:
			return (GPIOG->IDR & (1 << pin))==0? 0:1;
		default:
			break;
	}
}
