/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ָ��ʶ��ģ��ʵ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
#include "stm32f10x.h"
#include "./usart/bsp_usart.h"
#include "./usart/bsp_usart1.h"
#include "./usart/rx_data_queue.h"
#include "./SysTick/bsp_SysTick.h"
#include "./led/bsp_led.h"  
#include "./as608/as608_test.h"
#include "./as608/bsp_as608.h"
#include "./key/bsp_key.h" 
#include "./gps/gps_config.h"
#include "bsp_exti.h"
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
extern void nmea_decode_test(void);

int main(void)
{
/*���ڳ�ʼ��*/
	USART_Config();
  
  GPS_Config();

  printf("\r\n���� GPSģ���������\r\n"); 
  
	printf("\r\n�������GPSģ�鴮�ڴ��ص����ݽ��룬");
	printf("ʵ��ʱ������������GPSģ�� \r\n"); 
	printf("mainҳ1");
  /* GPS������� */
  nmea_decode_test();
  printf("mainҳ2");
  while(1);
	

}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
	
	
	
	


	




/*********************************************END OF FILE**********************/
