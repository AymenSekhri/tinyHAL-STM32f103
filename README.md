# STM32F103-HAL
 A basic Hardware Abstruction Layer for STM32F103, This project will provide simple abstruct routines to configure and use STM32F103 microprocessor, without having to know much about Cortex-M3 architecture. I'm using this project to learn more about coding bare metal in this microprocessor.
## Peripheral that will be covered
- [x] GPIO
- [X] UART
- [X] Timers
- [ ] Interrupts
- [ ] SPI
- [ ] I2C
- [ ] ADC
- [ ] LCD
## Environment
 The source code is compiled using **Keil uVision 5** IDE, I chose it because of it gread debugging tools. Though, you can use any compiler/IDE since the code is bare metal, it doesn't depend on any HAL, except `stm32f10x.h` header which contains the structures and address of all stmf103 configuration registers, you can find it online.
 
