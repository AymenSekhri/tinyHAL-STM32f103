#include "interrupts.h"


void enableIRQ(int irq, int priority){
	__COMPILER_BARRIER();
	NVIC->IP[irq]	|= (priority & 0xF) << 4;
	NVIC->ISER[irq>>5] |= (1 << (irq&0x1F));
}

void disableIRQ(int irq){
	__COMPILER_BARRIER();
	NVIC->ICER[irq>>5] |= (1 << (irq&0x1F));
}

void setPendingIRQ(int irq){
	__COMPILER_BARRIER();
	NVIC->ISPR[irq>>5] |= (1 << (irq&0x1F));
}

void clearPendingIRQ(int irq){
	__COMPILER_BARRIER();
	NVIC->ICPR[irq>>5] |= (1 << (irq&0x1F));
}


void enableInterrupts(){
	__enable_irq();
}

void disableInterrupts(){
	__disable_irq();
}