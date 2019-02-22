/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2014-08-xx
  * @brief   gps模块演示测试程序
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 ISO-STM32 开发板
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
	*/
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "gps_config.h"
#include <string.h>
#include"gsm.h"
#include<stdio.h>

		

extern void nmea_decode_test(void);

/*
 * 测试GPS模块功能
 * 
 */
 
 
double  zaishichua;
double  zaishichub;
int main(void)
{
	char zaiship1[14];
	char zaiship2[14];
    /* 配置USART1 用于向电脑printf调试信息*/
   USART1_Config();                          
    /* 初始化GPS模块使用的接口 */
    GPS_Config();
    
    printf("\r\n野火WF-NEO-6M GPS模块测试例程\r\n");               /////////////////////////////////
  
    /* GPS解码测试 */
    nmea_decode_test();
    printf("\r\n纬度：%f,经度%f\r\n",zaishichua,zaishichub);
	 printf("\r\n纬度：%f,经度%f\r\n",zaishichua,zaishichub);
   

  	sprintf(zaiship1,"%013.6f",zaishichua);
	  sprintf(zaiship2,"%013.6f",zaishichub);
	   gsm(zaiship1,zaiship2);



	  while(1);
  
  
}



