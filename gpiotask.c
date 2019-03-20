/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "system_stm32f10x.h"
#include  "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xtaskhandle1=NULL;

void vTask1_handler(void *param);
void delay(unsigned int nCount);
GPIO_InitTypeDef GPIO_InitStruct;

int main (void)
{


    // Enable clock for GPIOA
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);


    // Configure PA0 as push-pull output
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;


    GPIO_Init(GPIOC, &GPIO_InitStruct);


    xTaskCreate(vTask1_handler,"Task1",configMINIMAL_STACK_SIZE,NULL,2,&xtaskhandle1);

    vTaskStartScheduler();


    while (1)
    {

    }
}


void vTask1_handler(void *param)
{
	while(1){
        /* Toggle LED on PA0 */
        // Reset bit will turn on LED (because the logic is interved)
    		//	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
    			GPIO_WriteBit(GPIOC,GPIO_Pin_13,0);
    	        delay(100);
    	        // Set bit will turn off LED (because the logic is interved)
    	       // GPIO_SetBits(GPIOC, GPIO_Pin_13);
    	        GPIO_WriteBit(GPIOC,GPIO_Pin_13,1);

    	        delay(100);

	}
}

// Delay function
void delay(unsigned int nCount)
{
    unsigned int i, j;

    for (i = 0; i < nCount; i++)
        for (j = 0; j < 0x2AFF; j++);
}
