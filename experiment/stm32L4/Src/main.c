///**
// ******************************************************************************
// * @file           : main.c
// * @author         : Chris Dedman
// * @brief          : Main program body
// ******************************************************************************
// */

#include <stdint.h>
#include <stdio.h>

extern void initialise_monitor_handles();

int main(void)
{
    initialise_monitor_handles(); // Enable semihosting for printf() if required

    // Define pointers to memory-mapped registers
    uint32_t *pClockRegister     = (uint32_t*) 0x4002104C;  // RCC AHB2ENR
    uint32_t *pPortBModeRegister = (uint32_t*) 0x48000400;  // GPIOB MODER
    uint32_t *pPortBDataRegister = (uint32_t*) 0x48000414;  // GPIOB ODR

    uint32_t *pPortAModeRegister = (uint32_t*) 0x48000000;  // GPIOA MODER
    uint32_t *pPortADataRegister = (uint32_t*) 0x48000014;  // GPIOA ODR

    // 1. Enable the clock for GPIOB peripheral in the AHB2ENR (SET the 1st bit position)
    *pClockRegister |= (1 << 1);

    // 2. Configure the mode of the IO pin as output (PB14)
    // a. Clear the 28th and 29th bit positions (CLEAR)
    *pPortBModeRegister &= ~(3 << 28); // PB14 is at bit positions 28 and 29
    // b. Set the 28th bit position as 1 (SET)
    *pPortBModeRegister |= (1 << 28);

    // 3. Set the 14th bit of the output data register to make I/O pin-12 HIGH
	*pPortBDataRegister |= (1 << 14);

    // Repeat the above steps for GPIOA pin 5 (PA5)
	*pClockRegister |= (1 << 0);
	*pPortAModeRegister &= ~(3 << 10);
	*pPortAModeRegister |= (1 << 10);
	*pPortADataRegister |= (1 << 5);

	while(1);

    return 0;
}
