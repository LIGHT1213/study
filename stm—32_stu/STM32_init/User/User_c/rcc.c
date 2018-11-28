/**
  * @file    rcc.c
  * @brief   STM32F407xx Clock Config and Initial Funtion
*/
#include "rcc.h"
#include"stm32f4xx_rcc.h"

#define RCC_PLLSource RCC_PLLSource_HSE
#define PLLM_S 8
#define PLLN_S 336
#define PLLP_S 2
#define PLLQ_S 7


/**
  * @brief  Setup the STM32F407xx's clock as follow :
  * -----------------------------------------------------------------------------
  *        System Clock source                    | PLL (HSE)
  *-----------------------------------------------------------------------------
  *        SYSCLK(Hz)                             | 168000000
  *-----------------------------------------------------------------------------
  *        HCLK(Hz)                               | 168000000
  *-----------------------------------------------------------------------------
  *        AHB Prescaler                          | 1
  *-----------------------------------------------------------------------------
  *        APB1 Prescaler                         | 4
  *-----------------------------------------------------------------------------
  *        APB2 Prescaler                         | 2
  *-----------------------------------------------------------------------------
  *        HSE Frequency(Hz)                      | 8000000
  *-----------------------------------------------------------------------------
  *        PLL_M                                  | 8
  *-----------------------------------------------------------------------------
  *        PLL_N                                  | 336
  *-----------------------------------------------------------------------------
  *        PLL_P                                  | 2
  *-----------------------------------------------------------------------------
  *        PLL_Q                                  | 7
  *-----------------------------------------------------------------------------
  *        PLLI2S_N                               | NA
  *-----------------------------------------------------------------------------
  *        PLLI2S_R                               | NA
  *-----------------------------------------------------------------------------
  * @param  None
  * @retval None
  */
void HSE_SetsysColock(void)
{
  ErrorStatus HSESTARTUP_FLAG = ERROR;
  
  uint16_t counter = 0;
  
  RCC_DeInit();
  RCC_ClearFlag();
  
  //HSEConfig
  RCC_HSEConfig(RCC_HSE_ON);
  
  do
  {
    HSESTARTUP_FLAG = RCC_WaitForHSEStartUp();
    counter ++;
  }
  while(HSESTARTUP_FLAG != SUCCESS);
  
  //PLLCONFIG
  PLLCONFIG:
  counter = 0;
  RCC_PLLCmd(DISABLE);
  RCC_PLLConfig(RCC_PLLSource , PLLM_S , PLLN_S , PLLP_S , PLLQ_S);
  RCC_PLLCmd(ENABLE);
  
  while((!RCC_GetFlagStatus(RCC_FLAG_PLLRDY)) && (counter <= 100))
  {
    counter ++;
  }
  if(counter >= 100)
  {
    goto PLLCONFIG;
  }
  
  //SYSCLKCONFIG
  SYSCLKCONFIG:
  counter = 0;
  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
  
  while((RCC_GetSYSCLKSource() != 0x08) && counter <= 100)
  {
    counter ++;
  }
  if(counter >= 100)
  {
    goto SYSCLKCONFIG;
  }
  
  //HCLK Config
  RCC_HCLKConfig(RCC_SYSCLK_Div1);
  //PCLK1(APB1) Config
  RCC_PCLK1Config(RCC_HCLK_Div4);
  //PCLK2(APB2) Config
  RCC_PCLK2Config(RCC_HCLK_Div2);
  
  RCC_ClearFlag();
  
  
  //Additional wait , make sure the clock is stable.
  counter  = 5000;
  while(counter > 1)
  {
    counter --;
  }
  
  counter = 0;
  
}
