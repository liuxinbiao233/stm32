#ifndef __GPS_CONFIG_H
#define	__GPS_CONFIG_H

#include "stm32f10x.h"
#include "nmea/nmea.h"


/* ���� */

//#define __GPS_DEBUG     //��������꣬��nmea����ʱ�����������Ϣ

//#define __GPS_LOG_FILE    //��������꣬��SD���ϵ�gpslog.txt�ļ����н��룻������Ļ�ʹ�ô���2����GPS��Ϣ����


/* GPS�ӿ����� ʹ�ò�ͬ�Ĵ���ʱ��Ҫ�޸Ķ�Ӧ�Ľӿ� */

#define USART3_DR_Base            (0x40004800+0x04)		  // ����2�����ݼĴ�����ַ,�˴���Ϊ����3����ʱҪע���ַҲҪ��


#define GPS_DATA_ADDR             USART3_DR_Base        //GPSʹ�õĴ��ڵ����ݼĴ�����ַ
#define GPS_RBUFF_SIZE            512                   //���ڽ��ջ�������С
#define HALF_GPS_RBUFF_SIZE       (GPS_RBUFF_SIZE/2)    //���ڽ��ջ�����һ��  

/* ���� */
#define GPS_USART                    USART3
#define GPS_DMA                      DMA1
#define GPS_DMA_CLK                  RCC_AHBPeriph_DMA1
#define GPS_DMA_CHANNEL              DMA1_Channel3
#define GPS_DMA_IRQn                 DMA1_Channel3_IRQn         //GPS�ж�Դ

/* �����־ */
#define GPS_DMA_FLAG_TC              DMA1_FLAG_TC3
#define GPS_DMA_FLAG_TE              DMA1_FLAG_TE3
#define GPS_DMA_FLAG_HT              DMA1_FLAG_HT3
#define GPS_DMA_FLAG_GL              DMA1_FLAG_GL3
#define GPS_DMA_IT_HT                DMA1_IT_HT3
#define GPS_DMA_IT_TC                DMA1_IT_TC3


/* ���� */
#define GPS_USART_INIT               USART3_Config              //GPSʹ�õĴ��ڳ�ʼ��������������9600 
#define GPS_DMA_IRQHANDLER           DMA1_Channel3_IRQHandler   //GPSʹ�õ�DMA�жϷ�����


extern uint8_t gps_rbuff[GPS_RBUFF_SIZE];
extern __IO uint8_t GPS_TransferEnd ;
extern __IO uint8_t GPS_HalfTransferEnd;
extern double  zaishichua;
extern double  zaishichub;

void GPS_ProcessDMAIRQ(void);
void GPS_Config(void);

void trace(const char *str, int str_size);
void error(const char *str, int str_size);
void GMTconvert(nmeaTIME *SourceTime, nmeaTIME *ConvertTime, uint8_t GMT,uint8_t AREA) ;




#endif 
