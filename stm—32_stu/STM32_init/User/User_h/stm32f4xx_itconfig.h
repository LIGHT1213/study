/**
  * @file    stm32f4xx_itconfig.h
  * @brief   STM32F407xx interrupt config funtion's header , edit by user.
*/
#ifdef STM32F4XX_ITCONFIG_H
#endif

#define STM32F4XX_ITCONFIG_H

#include"stdint.h"
#include"stm32f4xx.h"
#include"core_cm4.h"
#include"stm32f4xx_gpio.h"
#include"misc.h"
#include"stm32f4xx_it.h"
#include"rcc.h"
#include"stm32f4xx_exti.h"
#include"stm32f4xx_syscfg.h"
#include "stm32f4xx_usart.h"

void system_nvicinit(void);
void exit_initconfig(void);
void uart1_init(void);
