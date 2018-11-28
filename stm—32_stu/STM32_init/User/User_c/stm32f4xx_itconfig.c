/**
  * @file    stm32f4xx_itconfig.c
  * @brief   All STM32F407xx interrupt config funtion will write in here , edit by user.
*/
#include"stm32f4xx_itconfig.h"


void system_nvicinit(void)
{
  /*
   * 设置优先级分组 2个抢占式优先级 0 1 
   *                8个先后优先级 0 到 7 
  */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
}

void exit_initconfig(void)
{
  
  /*
   * 外部中断初始化设置
  */
  NVIC_InitTypeDef nvicinit;
  EXTI_InitTypeDef exti11init;
  
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOF , EXTI_PinSource11);
  
  nvicinit.NVIC_IRQChannel = EXTI15_10_IRQn;
  nvicinit.NVIC_IRQChannelPreemptionPriority = 1;
  nvicinit.NVIC_IRQChannelSubPriority = 7;
  nvicinit.NVIC_IRQChannelCmd = ENABLE;
  
  NVIC_Init(&nvicinit);
  
  exti11init.EXTI_Line = EXTI_Line11;
  exti11init.EXTI_Mode = EXTI_Mode_Interrupt;
  exti11init.EXTI_Trigger = EXTI_Trigger_Rising;
  exti11init.EXTI_LineCmd = ENABLE;
  
  EXTI_Init(&exti11init);
}

void uart1_init(void)
{
  
  /*
   * 串口1初始化函数 串口1 TX PA9
   *                       RX PA10
   *              配置模式 9600 N 8 1 
                           普通UART模式 无时钟同步线
  */
  NVIC_InitTypeDef nvicinit;
	USART_InitTypeDef usart1_init;
  GPIO_InitTypeDef gpio_init;
  
  /*
   * 相关外设时钟配置
  */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 , ENABLE);
  
  gpio_init.GPIO_OType = GPIO_OType_PP;
  gpio_init.GPIO_PuPd = GPIO_PuPd_UP;
  gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
  gpio_init.GPIO_Mode = GPIO_Mode_AF;
  gpio_init.GPIO_Pin = GPIO_Pin_9;
  
  GPIO_Init(GPIOA , &gpio_init);
  
  gpio_init.GPIO_Mode = GPIO_Mode_AF;
  gpio_init.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA , &gpio_init);
  
  /*将USART设置到 PA9 PA10*/
  GPIO_PinAFConfig(GPIOA , GPIO_PinSource9 , GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA , GPIO_PinSource10 , GPIO_AF_USART1);
  
  /*
   * NVIC中断配置  抢占优先级1 最高0
   *               先后优先级6 最高0
  */
  nvicinit.NVIC_IRQChannel = USART1_IRQn;
  nvicinit.NVIC_IRQChannelPreemptionPriority = 1;
  nvicinit.NVIC_IRQChannelSubPriority = 6;
  nvicinit.NVIC_IRQChannelCmd = ENABLE;
  
  
  /*
   * 关闭硬件流控制 允许TX RX 9600 N 8 1 
  */
  usart1_init.USART_BaudRate = 9600;
  usart1_init.USART_WordLength = USART_WordLength_8b;
  usart1_init.USART_StopBits = USART_StopBits_1;
  usart1_init.USART_Parity = USART_Parity_No;
  usart1_init.USART_Mode = (USART_Mode_Rx | USART_Mode_Tx);
  usart1_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  
  NVIC_Init(&nvicinit);
  
  USART_Init(USART1 , &usart1_init);
  
  USART_ITConfig(USART1 , USART_IT_RXNE , ENABLE);
  USART_ITConfig(USART1 , USART_IT_TC , ENABLE);
  
  
  USART_Cmd(USART1 , ENABLE);
  
  
}

