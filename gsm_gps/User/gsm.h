#ifndef   _GSM_H
#define   _GSM_H
#include "stm32f10x.h"
#include "bsp_usart2.h"
#include "bsp_SysTick.h"
#include "sim900a.h"
#include <string.h>
#define CLI()      __set_PRIMASK(1)		/* �ر����ж� */  
#define SEI() __set_PRIMASK(0)				/* �������ж� */ 


/* ���ն��ŵĵ绰���� */
extern int gsm(char *p1,char *p2);
#endif

