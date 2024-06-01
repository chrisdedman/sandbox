///**
// ******************************************************************************
// * @file           : main.c
// * @author         : Chris Dedman
// * @brief          : Main program body
// ******************************************************************************
// */

#include <stdint.h>
#include <stdio.h>
#include "main.h"

// extern void initialise_monitor_handles(); // Semihosting (uncomment if required)

int main(void)
{
    // initialise_monitor_handles(); // Enable semihosting for printf debugging (uncomment if required)

    RCC_AHB2ENR_t volatile *const pClockRegister     = (RCC_AHB2ENR_t*) 0x4002104C;
    GPIOx_MODER_t volatile *const pPortBModeRegister = (GPIOx_MODER_t*) 0x48000400;
    GPIOx_MODER_t volatile *const pPortAModeRegister = (GPIOx_MODER_t*) 0x48000000;
    GPIOx_ODR_t volatile *const pPortBDataRegister   = (GPIOx_ODR_t*) 0x48000414;
    GPIOx_ODR_t volatile *const pPortADataRegister   = (GPIOx_ODR_t*) 0x48000014;

    pPortAModeRegister->pin_5 = 1;
    pPortBModeRegister->pin_14 = 1;

    pClockRegister->GPIOA_EN = 1;
    pClockRegister->GPIOB_EN = 1;

    while(1)
    {
        pPortADataRegister->pin_5 = 1;
        pPortBDataRegister->pin_14 = 1;

        for (volatile uint32_t i = 0; i < 300000; i++);

        pPortADataRegister->pin_5 = 0;
        pPortBDataRegister->pin_14 = 0;

        for (volatile uint32_t i = 0; i < 300000; i++);
    }

    return 0;
}