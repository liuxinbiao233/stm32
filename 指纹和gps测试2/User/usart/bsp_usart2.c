/**
  ******************************************************************************
  * @file    bsp_as608.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ָ��ʶ��ģ��ʵ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����STM32 F103-�Ե� ������  
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "./as608/bsp_as608.h"
#include "./usart/rx_data_queue.h"
#include "./SysTick/bsp_SysTick.h"
#include "./usart/bsp_usart1.h" 
#include <stdarg.h>




 /**
  * @brief  ����Ƕ�������жϿ�����NVIC
  * @param  ��
  * @retval ��
  */	
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Ƕ�������жϿ�������ѡ�� */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* ����USARTΪ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* �����ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ʹ���ж� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure);
  /* �����ж�Դ��TouchOut�� */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* ���������ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure); 
}


  /**
  * @brief  AS608_TouchOut����
  * @param  ��
  * @retval ��
  */
void AS608_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  
	/*��������GPIO�ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
  AS608_USART_GPIO_APBxClkCmd((RCC_APB2Periph_GPIOA), ENABLE);
  /*�򿪴��������ʱ��*/
	AS608_USART_APBxClkCmd(RCC_APB1Periph_USART2, ENABLE);
												
	/* ���� NVIC �ж�*/
	NVIC_Configuration();
  
	/* TouchOut���õ���GPIO */	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  /* ����Ϊ�������� */	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* ѡ��EXTI���ź�Դ */
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4); 
  EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	
	/* EXTIΪ�ж�ģʽ */
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* ����/�½����ж� */
  EXTI_InitStructure.EXTI_Trigger =EXTI_Trigger_Rising_Falling;
  /* ʹ���ж� */	
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  
  /*��USART Tx��GPIO����Ϊ���츴��ģʽ*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

  /*��USART Rx��GPIO����Ϊ��������ģʽ*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/*���ô��ڵĹ�������*/
	/*���ò�����*/
	USART_InitStructure.USART_BaudRate = 57600;
	/*���� �������ֳ�*/
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	/*����ֹͣλ*/
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	/*����У��λ*/
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	/*����Ӳ��������*/
	USART_InitStructure.USART_HardwareFlowControl = 
	                                USART_HardwareFlowControl_None;
	/*���ù���ģʽ���շ�һ��*/
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	/*��ɴ��ڵĳ�ʼ������*/
	USART_Init(USART2, &USART_InitStructure);
	
	/*ʹ�ܴ��ڽ����ж�*/
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);	
	USART_ITConfig(USART2, USART_IT_IDLE, ENABLE ); //ʹ�ܴ������߿����ж� 	
	
	/*ʹ�ܴ���*/
	USART_Cmd(USART2, ENABLE);	
 	
}






/*********************************************END OF FILE**********************/

