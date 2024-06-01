#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct
{
  uint32_t GPIOA_EN     : 1;
  uint32_t GPIOB_EN     : 1;
  uint32_t GPIOC_EN     : 1;
  uint32_t GPIOD_EN     : 1;
  uint32_t GPIOE_EN     : 1;
  uint32_t GPIOF_EN     : 1;
  uint32_t GPIOG_EN     : 1;
  uint32_t GPIOH_EN     : 1;
  uint32_t GPIOI_EN     : 1;
  uint32_t reserverd_1  : 3;
  uint32_t OTGFS_EN     : 1;
  uint32_t ADC_EN       : 1;
  uint32_t DCMI_EN      : 1;
  uint32_t reserverd_2  : 1;
  uint32_t AES_EN       : 1;
  uint32_t HASH_EN      : 1;
  uint32_t RNG_EN       : 1;
  uint32_t reserverd_3  : 13;

} RCC_AHB2ENR_t;

typedef struct
{
  uint32_t pin_0    : 2;
  uint32_t pin_1    : 2;
  uint32_t pin_2    : 2;
  uint32_t pin_3    : 2;
  uint32_t pin_4    : 2;
  uint32_t pin_5    : 2;
  uint32_t pin_6    : 2;
  uint32_t pin_7    : 2;
  uint32_t pin_8    : 2;
  uint32_t pin_9    : 2;
  uint32_t pin_10   : 2;
  uint32_t pin_11   : 2;
  uint32_t pin_12   : 2;
  uint32_t pin_13   : 2;
  uint32_t pin_14   : 2;
  uint32_t pin_15   : 2;

} GPIOx_MODER_t;

typedef struct
{
  uint32_t pin_0    : 1;
  uint32_t pin_1    : 1;
  uint32_t pin_2    : 1;
  uint32_t pin_3    : 1;
  uint32_t pin_4    : 1;
  uint32_t pin_5    : 1;
  uint32_t pin_6    : 1;
  uint32_t pin_7    : 1;
  uint32_t pin_8    : 1;
  uint32_t pin_9    : 1;
  uint32_t pin_10   : 1;
  uint32_t pin_11   : 1;
  uint32_t pin_12   : 1;
  uint32_t pin_13   : 1;
  uint32_t pin_14   : 1;
  uint32_t pin_15   : 1;
  uint32_t reserved : 16;

} GPIOx_ODR_t;

#endif /* MAIN_H_ */