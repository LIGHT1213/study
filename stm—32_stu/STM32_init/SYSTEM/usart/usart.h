#ifndef __USART_H
#define __USART_H 
#include "sys.h"
#include "stdio.h"	  
#define USART_REC_LEN  			
#define EN_USART1_RX 				
extern u8  USART_RX_BUF[USART_REC_LEN]; 
extern u16 USART_RX_STA;         		
void uart_init(u32 bound);
#endif	   
















