
#include"gsm.h"
const char num[]="15627861298";
int gsm(char *p1,char *p2)
{
    USART2_Config();
    SysTick_Init();
    sim900a_sms((char *)num,p1);
		SIM900A_DELAY(5000);               //////////////////////////延时是必须的，因为模块接收信息再传输需要时间
		sim900a_sms((char *)num,p2);
  
	return 0;
}



