#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
//#include "bsp_usart1.h"
#include "bsp_usart2.h"
#include "sim900a.h"
  


void sim900a_sms(char *num,char *smstext)
{
  //  char ucsbuff[160];
    SIM900A_CLEAN_RX();                 //����˽��ջ���������
        //Ӣ��
        sim900a_tx_printf("AT+CSCS=\"GSM\"\r");     //"GSM"�ַ���
        SIM900A_DELAY(100);
        
        sim900a_tx_printf("AT+CMGF=1\r");           //�ı�ģʽ
        SIM900A_DELAY(100);
        
        sim900a_tx_printf("AT+CMGS=\"%s\"\r",num);  //�绰����
        SIM900A_DELAY(100);

        sim900a_tx_printf("%s",smstext);            //��������
        //SIM900A_DELAY(100);          
    
     
    SIM900A_DELAY(1); 
    USART2->DR=(u32)0x1A;		//����ʮ����������0X1A,��Ϣ��������//////////////////(gsmģ�����Դ�Ϊ��־λ���ŷ��Ͷ���)
}





/*---------------------------------------------------------------------*/
