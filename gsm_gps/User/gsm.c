
#include"gsm.h"
const char num[]="15627861298";
int gsm(char *p1,char *p2)
{
    USART2_Config();
    SysTick_Init();
    sim900a_sms((char *)num,p1);
		SIM900A_DELAY(5000);               //////////////////////////��ʱ�Ǳ���ģ���Ϊģ�������Ϣ�ٴ�����Ҫʱ��
		sim900a_sms((char *)num,p2);
  
	return 0;
}



