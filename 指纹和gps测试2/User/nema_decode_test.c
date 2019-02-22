/**
  ******************************************************************************
  * @file    nmea_decode_test.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试NEMA解码库
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "stm32f10x.h"

#include "bsp_usart1.h"	
#include "bsp_usart3.h"
#include "../nmea/nmea.h"
#include "gps_config.h"

  



/**
  * @brief  nmea_decode_test 解码GPS模块信息
  * @param  无
  * @retval 无
  */
int nmea_decode_test(void)//文件中使用的应该是这个函数
{
		double zaishichua;//转换成[degree].[degree]格式的纬度
		double zaishichub;//转换成[degree].[degree]格式的经度
    nmeaINFO info;          //GPS解码后得到的信息，为结构体
    nmeaPARSER parser;      //解码时使用的数据结构  
    uint8_t new_parse=0;    //是否有新的解码数据标志
  
    nmeaTIME beiJingTime;    //北京时间 

    /* 设置用于输出调试信息的函数 */
    nmea_property()->trace_func = &trace;
    nmea_property()->error_func = &error;

    /* 初始化GPS数据结构 */
    nmea_zero_INFO(&info);
    nmea_parser_init(&parser);
	
  
while(!GPS_HalfTransferEnd);	  
while(GPS_HalfTransferEnd)
  {
      if(GPS_HalfTransferEnd)     /* 接收到GPS_RBUFF_SIZE一半的数据 */
      {
        /* 进行nmea格式解码 */
        nmea_parse(&parser, (const char*)&gps_rbuff[0], HALF_GPS_RBUFF_SIZE, &info);
        
        GPS_HalfTransferEnd = 0;   //清空标志位
        new_parse = 1;             //设置解码消息标志                                 ////////////////////////////////////////////
      }
      else if(GPS_TransferEnd)    /* 接收到另一半数据 */                ///////////////////////////注意每一半的缓存区都足够储存一次完整的GPS的数据，此处不是把一次GPS数据分成两部分；
      {

        nmea_parse(&parser, (const char*)&gps_rbuff[HALF_GPS_RBUFF_SIZE], HALF_GPS_RBUFF_SIZE, &info);
       
        GPS_TransferEnd = 0;
        new_parse =1;
      }
      
      if(new_parse )                //有新的解码消息   
      {   

				zaishichua=info.lat;///////////////////////////////////////////////////////////
				zaishichub=info.lon;/////////////////////////////////////////////////////////////
        /* 对解码后的时间进行转换，转换成北京时间 */
        GMTconvert(&info.utc,&beiJingTime,8,1);
        
        /* 输出解码得到的信息 */
        printf("\r\n时间%d,%d,%d,%d,%d,%d\r\n", beiJingTime.year+1900, beiJingTime.mon+1,beiJingTime.day,beiJingTime.hour,beiJingTime.min,beiJingTime.sec);
        printf("\r\n纬度：%f,经度%f\r\n",info.lat,info.lon);
        printf("\r\n纬度：%f,经度%f\r\n",zaishichua,zaishichub);///////////////////////////////////////////
				printf("\r\n正在使用的卫星：%d,可见卫星：%d",info.satinfo.inuse,info.satinfo.inview);
        printf("\r\n海拔高度：%f 米 ", info.elv);
        printf("\r\n速度：%f km/h ", info.speed);
        printf("\r\n航向：%f 度", info.direction);
        
        new_parse = 0;
      }
	
	}

    /* 释放GPS数据结构 */
    // nmea_parser_destroy(&parser);

    
      return 0;
}









/**************************************************end of file****************************************/

