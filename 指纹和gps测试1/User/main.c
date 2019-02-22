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
  * @brief  主函数
  * @param  无
  * @retval 无
  */
extern void nmea_decode_test(void);

int main(void)
{
/*串口初始化*/
	USART_Config();
  
  GPS_Config();

  printf("\r\n秉火 GPS模块测试例程\r\n"); 
  
	printf("\r\n本程序对GPS模块串口传回的数据解码，");
	printf("实验时请给开发板接入GPS模块 \r\n"); 
	printf("main页1");
  /* GPS解码测试 */
  nmea_decode_test();
  printf("main页2");
  while(1);
	

}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
	
	
	
	


	




/*********************************************END OF FILE**********************/
