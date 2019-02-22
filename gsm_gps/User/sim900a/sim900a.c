#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
//#include "bsp_usart1.h"
#include "bsp_usart2.h"
#include "sim900a.h"
  


void sim900a_sms(char *num,char *smstext)
{
  //  char ucsbuff[160];
    SIM900A_CLEAN_RX();                 //清空了接收缓冲区数据
        //英文
        sim900a_tx_printf("AT+CSCS=\"GSM\"\r");     //"GSM"字符集
        SIM900A_DELAY(100);
        
        sim900a_tx_printf("AT+CMGF=1\r");           //文本模式
        SIM900A_DELAY(100);
        
        sim900a_tx_printf("AT+CMGS=\"%s\"\r",num);  //电话号码
        SIM900A_DELAY(100);

        sim900a_tx_printf("%s",smstext);            //短信内容
        //SIM900A_DELAY(100);          
    
     
    SIM900A_DELAY(1); 
    USART2->DR=(u32)0x1A;		//发送十六进制数：0X1A,信息结束符号//////////////////(gsm模块中以此为标志位，才发送短信)
}





/*---------------------------------------------------------------------*/
