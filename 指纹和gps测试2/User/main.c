/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   指纹识别模块实验
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  * @brief  主函数
  * @param  无
  * @retval 无
  */
extern void nmea_decode_test(void);	
 

double  zaishichua;
double  zaishichub;

int main(void)
{		
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
  
  LED_GPIO_Config();	
  
  /*初始化环形缓冲区*/
  rx_queue_init();
   
  /*初始化指纹模块配置*/
	AS608_Config();
  
	/*测试STM32与指纹模块的通信*/
  Connect_Test();
	 while(1)
  {
    FR_Task();
  } 
	

	
	 GPS_Config();
    
    printf("\r\n野火WF-NEO-6M GPS模块测试例程\r\n");               /////////////////////////////////
  
    /* GPS解码测试 */
    nmea_decode_test();
    printf("\r\n纬度：%f,经度%f\r\n",zaishichua,zaishichub);
	 printf("\r\n纬度：%f,经度%f\r\n",zaishichua,zaishichub);
  


	//while(1)
//	{

		//如果KEY1被单击，切换gps模式
//		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON  )
//			printf("现在是gps模式");
  
//		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON  )
//			printf("现在是指纹模式");
//	}
}


/*********************************************END OF FILE**********************/
