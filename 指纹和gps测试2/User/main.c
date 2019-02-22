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
#include "./usart/bsp_usart1.h"
#include "./usart/rx_data_queue.h"
#include "./SysTick/bsp_SysTick.h"
#include "./led/bsp_led.h"  
#include "./as608/as608_test.h"
#include "./as608/bsp_as608.h"
#include "../gps/gps_config.h"
#include "./key/bsp_key.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
extern void nmea_decode_test(void);	
 

double  zaishichua;
double  zaishichub;

int main(void)
{		
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
  
  LED_GPIO_Config();	
  
  /*��ʼ�����λ�����*/
  rx_queue_init();
   
  /*��ʼ��ָ��ģ������*/
	AS608_Config();
  
	/*����STM32��ָ��ģ���ͨ��*/
  Connect_Test();
	 while(1)
  {
    FR_Task();
  } 
	

	
	 GPS_Config();
    
    printf("\r\nҰ��WF-NEO-6M GPSģ���������\r\n");               /////////////////////////////////
  
    /* GPS������� */
    nmea_decode_test();
    printf("\r\nγ�ȣ�%f,����%f\r\n",zaishichua,zaishichub);
	 printf("\r\nγ�ȣ�%f,����%f\r\n",zaishichua,zaishichub);
  


	//while(1)
//	{

		//���KEY1���������л�gpsģʽ
//		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON  )
//			printf("������gpsģʽ");
  
//		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON  )
//			printf("������ָ��ģʽ");
//	}
}


/*********************************************END OF FILE**********************/
