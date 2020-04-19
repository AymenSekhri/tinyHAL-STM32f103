#include "stm32f103_hal_core.h"

void setGPIOBit(int port,int pin,bool value);
void setGPIOBitLow(int port,int pin);
void setGPIOBitHigh(int port,int pin);
bool readGPIOBit(int port,int pin);