/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2014-08-xx
  * @brief   gpsģ����ʾ���Գ���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ISO-STM32 ������
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
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
 * ����GPSģ�鹦��
 * 
 */
 
 
double  zaishichua;
double  zaishichub;
int main(void)
{
	char zaiship1[14];
	char zaiship2[14];
    /* ����USART1 ���������printf������Ϣ*/
   USART1_Config();                          
    /* ��ʼ��GPSģ��ʹ�õĽӿ� */
    GPS_Config();
    
    printf("\r\nҰ��WF-NEO-6M GPSģ���������\r\n");               /////////////////////////////////
  
    /* GPS������� */
    nmea_decode_test();
    printf("\r\nγ�ȣ�%f,����%f\r\n",zaishichua,zaishichub);
	 printf("\r\nγ�ȣ�%f,����%f\r\n",zaishichua,zaishichub);
   

  	sprintf(zaiship1,"%013.6f",zaishichua);
	  sprintf(zaiship2,"%013.6f",zaishichub);
	   gsm(zaiship1,zaiship2);



	  while(1);
  
  
}



