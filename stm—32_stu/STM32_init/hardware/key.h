#include "stm32f4xx.h"
#ifndef __KEY_H
#define __KEY_H	 

#define KEY1   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define KEY2   GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11)
#define KEY3   GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)
#define KEY4   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
#define KEY1_Press 1   
#define KEY2_Press 2    
#define KEY3_Press 3    
#define KEY4_Press 4 

void keyinit(void);
u8 keyscan(u8);

#endif
