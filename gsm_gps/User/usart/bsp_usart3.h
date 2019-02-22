#ifndef __USART3_H
#define	__USART3_H

#include "stm32f10x.h"
#include <stdio.h>





void USART3_Config(void);
//int fputc(int ch, FILE *f);
void USART3_printf(USART_TypeDef* USARTx, char *Data,...);


extern char *get_rebuff(uint8_t *len);
extern void clean_rebuff(void);

#endif /* __USART2_H */
