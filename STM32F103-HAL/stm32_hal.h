#include "stm32f10x.h"
#include "stdbool.h"


#define MASK(Down,Up) (Down | Up << 16)
#define UPPERWORD(X) ((X & 0xFFFF0000) >> 16)
#define LOWERWORD(X) ((X & 0x0000FFFF))



#define BUS_AHB 1
#define BUS_APB1 2
#define BUS_APB2 3

#define Peripheral_AFIO  		MASK(0,BUS_APB2)
#define Peripheral_GPIOA 		MASK(2,BUS_APB2)
#define Peripheral_GPIOB 		MASK(3,BUS_APB2)
#define Peripheral_GPIOC 		MASK(4,BUS_APB2)
#define Peripheral_GPIOD 		MASK(5,BUS_APB2)
#define Peripheral_GPIOE 		MASK(6,BUS_APB2)
#define Peripheral_GPIOF 		MASK(7,BUS_APB2)
#define Peripheral_GPIOG 		MASK(8,BUS_APB2)
#define Peripheral_ADC1 		MASK (9,BUS_APB2)
#define Peripheral_ADC2 		MASK (10,BUS_APB2)
#define Peripheral_TIM1 		MASK (11,BUS_APB2)
#define Peripheral_SPI1 		MASK (12,BUS_APB2)
#define Peripheral_TIM8 		MASK (13,BUS_APB2)
#define Peripheral_USART1 	MASK(14,BUS_APB2)
#define Peripheral_ADC3  		MASK(15,BUS_APB2)

#define Peripheral_TIM9  		MASK(19,BUS_APB2)
#define Peripheral_TIM10  	MASK(20,BUS_APB2)
#define Peripheral_TIM11  	MASK(21,BUS_APB2)

#define GPIO_CONF_IN_ANALOG 							0
#define GPIO_CONF_IN_FLOAT				 				1
#define GPIO_CONF_IN_PUSHUP_PULLDOWN 			2
#define GPIO_CONF_OUT_PUSHPULL						0
#define GPIO_CONF_OUT_OPEN_DRAIN					1
#define GPIO_CONF_OUT_ALT_PUSHPULL				2
#define GPIO_CONF_OUT_ALT_OPENDRAIN				3


#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT_10MHZ 1
#define GPIO_MODE_OUT_02MHZ 2
#define GPIO_MODE_OUT_50MHZ 3



void enablePeripheralClock(int peripheral);
void configureGPIO(int port,int pin,int mode,int configuration);
void setGPIOBit(int port,int pin,bool value);
void setGPIOBitLow(int port,int pin);
void setGPIOBitHigh(int port,int pin);
