/**
  ******************************************************************************
  * @file    nmea_decode_test.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����NEMA�����
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "stm32f10x.h"

#include "bsp_usart1.h"	
#include "bsp_usart3.h"
#include "../nmea/nmea.h"
#include "gps_config.h"

  



/**
  * @brief  nmea_decode_test ����GPSģ����Ϣ
  * @param  ��
  * @retval ��
  */
int nmea_decode_test(void)//�ļ���ʹ�õ�Ӧ�����������
{
		double zaishichua;//ת����[degree].[degree]��ʽ��γ��
		double zaishichub;//ת����[degree].[degree]��ʽ�ľ���
    nmeaINFO info;          //GPS�����õ�����Ϣ��Ϊ�ṹ��
    nmeaPARSER parser;      //����ʱʹ�õ����ݽṹ  
    uint8_t new_parse=0;    //�Ƿ����µĽ������ݱ�־
  
    nmeaTIME beiJingTime;    //����ʱ�� 

    /* �����������������Ϣ�ĺ��� */
    nmea_property()->trace_func = &trace;
    nmea_property()->error_func = &error;

    /* ��ʼ��GPS���ݽṹ */
    nmea_zero_INFO(&info);
    nmea_parser_init(&parser);
	
  
while(!GPS_HalfTransferEnd);	  
while(GPS_HalfTransferEnd)
  {
      if(GPS_HalfTransferEnd)     /* ���յ�GPS_RBUFF_SIZEһ������� */
      {
        /* ����nmea��ʽ���� */
        nmea_parse(&parser, (const char*)&gps_rbuff[0], HALF_GPS_RBUFF_SIZE, &info);
        
        GPS_HalfTransferEnd = 0;   //��ձ�־λ
        new_parse = 1;             //���ý�����Ϣ��־                                 ////////////////////////////////////////////
      }
      else if(GPS_TransferEnd)    /* ���յ���һ������ */                ///////////////////////////ע��ÿһ��Ļ��������㹻����һ��������GPS�����ݣ��˴����ǰ�һ��GPS���ݷֳ������֣�
      {

        nmea_parse(&parser, (const char*)&gps_rbuff[HALF_GPS_RBUFF_SIZE], HALF_GPS_RBUFF_SIZE, &info);
       
        GPS_TransferEnd = 0;
        new_parse =1;
      }
      
      if(new_parse )                //���µĽ�����Ϣ   
      {   

				zaishichua=info.lat;///////////////////////////////////////////////////////////
				zaishichub=info.lon;/////////////////////////////////////////////////////////////
        /* �Խ�����ʱ�����ת����ת���ɱ���ʱ�� */
        GMTconvert(&info.utc,&beiJingTime,8,1);
        
        /* �������õ�����Ϣ */
        printf("\r\nʱ��%d,%d,%d,%d,%d,%d\r\n", beiJingTime.year+1900, beiJingTime.mon+1,beiJingTime.day,beiJingTime.hour,beiJingTime.min,beiJingTime.sec);
        printf("\r\nγ�ȣ�%f,����%f\r\n",info.lat,info.lon);
        printf("\r\nγ�ȣ�%f,����%f\r\n",zaishichua,zaishichub);///////////////////////////////////////////
				printf("\r\n����ʹ�õ����ǣ�%d,�ɼ����ǣ�%d",info.satinfo.inuse,info.satinfo.inview);
        printf("\r\n���θ߶ȣ�%f �� ", info.elv);
        printf("\r\n�ٶȣ�%f km/h ", info.speed);
        printf("\r\n����%f ��", info.direction);
        
        new_parse = 0;
      }
	
	}

    /* �ͷ�GPS���ݽṹ */
    // nmea_parser_destroy(&parser);

    
      return 0;
}









/**************************************************end of file****************************************/

