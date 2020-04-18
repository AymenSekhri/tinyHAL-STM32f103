#include "stm32f10x.h"
#include "stdbool.h"


#define MASK(Down,Up) (Down | Up << 16)
#define UPPERWORD(X) ((X & 0xFFFF0000) >> 16)
#define LOWERWORD(X) ((X & 0x0000FFFF))



#define BUS_AHB			1
#define BUS_APB1		2
#define BUS_APB2		3

#define Peripheral_AFIO  		MASK( 0,BUS_APB2)
#define Peripheral_GPIOA 		MASK( 2,BUS_APB2)
#define Peripheral_GPIOB 		MASK( 3,BUS_APB2)
#define Peripheral_GPIOC 		MASK( 4,BUS_APB2)
#define Peripheral_GPIOD 		MASK( 5,BUS_APB2)
#define Peripheral_GPIOE 		MASK( 6,BUS_APB2)
#define Peripheral_GPIOF 		MASK( 7,BUS_APB2)
#define Peripheral_GPIOG 		MASK( 8,BUS_APB2)
#define Peripheral_ADC1 		MASK( 9,BUS_APB2)
#define Peripheral_ADC2 		MASK(10,BUS_APB2)
#define Peripheral_TIM1 		MASK(11,BUS_APB2)
#define Peripheral_SPI1 		MASK(12,BUS_APB2)
#define Peripheral_TIM8 		MASK(13,BUS_APB2)
#define Peripheral_USART1 		MASK(14,BUS_APB2)
#define Peripheral_ADC3  		MASK(15,BUS_APB2)
#define Peripheral_TIM9  		MASK(19,BUS_APB2)
#define Peripheral_TIM10  		MASK(20,BUS_APB2)
#define Peripheral_TIM11  		MASK(21,BUS_APB2)

#define Peripheral_TIM2  		MASK( 0,BUS_APB1)
#define Peripheral_TIM3  		MASK( 1,BUS_APB1)
#define Peripheral_TIM4  		MASK( 2,BUS_APB1)
#define Peripheral_TIM5  		MASK( 3,BUS_APB1)
#define Peripheral_TIM6  		MASK( 4,BUS_APB1)
#define Peripheral_TIM7  		MASK( 5,BUS_APB1)
#define Peripheral_TIM12  		MASK( 6,BUS_APB1)
#define Peripheral_TIM13  		MASK( 7,BUS_APB1)
#define Peripheral_TIM14 		MASK( 8,BUS_APB1)
#define Peripheral_SPI2  		MASK(14,BUS_APB1)
#define Peripheral_SPI3  		MASK(15,BUS_APB1)
#define Peripheral_USART2  		MASK(17,BUS_APB1)
#define Peripheral_USART3  		MASK(18,BUS_APB1)
#define Peripheral_USART4  		MASK(19,BUS_APB1)
#define Peripheral_USART5  		MASK(20,BUS_APB1)
#define Peripheral_I2C1  		MASK(21,BUS_APB1)
#define Peripheral_I2C2  		MASK(22,BUS_APB1)
#define Peripheral_USB  		MASK(23,BUS_APB1)
#define Peripheral_CAN  		MASK(25,BUS_APB1)
#define Peripheral_BKP  		MASK(27,BUS_APB1)
#define Peripheral_PWR  		MASK(28,BUS_APB1)
#define Peripheral_DAC  		MASK(29,BUS_APB1)


#define GPIO_CONF_IN_ANALOG 					0
#define GPIO_CONF_IN_FLOAT						1
#define GPIO_CONF_IN_PUSHUP_PULLDOWN 			2
#define GPIO_CONF_OUT_PUSHPULL					0
#define GPIO_CONF_OUT_OPEN_DRAIN				1
#define GPIO_CONF_OUT_ALT_PUSHPULL				2
#define GPIO_CONF_OUT_ALT_OPENDRAIN				3


#define GPIO_MODE_IN							0
#define GPIO_MODE_OUT_10MHZ						1
#define GPIO_MODE_OUT_02MHZ						2
#define GPIO_MODE_OUT_50MHZ						3

#define USART1_CONF_TX_PIN		9		//PA9
#define USART1_CONF_RX_PIN		10		//PA10

#define USART2_CONF_TX_PIN		2		//PA2
#define USART2_CONF_RX_PIN		3		//PA3

#define USART3_CONF_TX_PIN		10		//PB10
#define USART3_CONF_RX_PIN		11		//PB11
#define USART_CONF_UE			(1<<13)
#define USART_CONF_TE			(1<<3)
#define USART_CONF_RE			(1<<2)

#define USART_STAT_TC			(1<<6)
#define USART_STAT_RXNE			(1<<5)

#define USART_MODE_RECEIVE				1
#define USART_MODE_TRANSMIT				2




void enablePeripheralClock(int peripheral);
void configureGPIO(int port,int pin,int mode,int configuration);
void setGPIOBit(int port,int pin,bool value);
void setGPIOBitLow(int port,int pin);
void setGPIOBitHigh(int port,int pin);
bool readGPIOBit(int port,int pin);
void USARTInitiate(int port, int baud, int mode);
void USARTSendByte(int port, char value);
void USARTSendStream(int port, char* data, int length);
void USARTSendString(int port, char* data);
char USARTReadByte(int port);
