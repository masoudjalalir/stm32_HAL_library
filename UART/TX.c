#include "main.h" //for detecting HAL library
#include "MyApp.h"

	

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_tx;
	
uint8_t data[2000];

uint8_t count=0;

void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==USART1)
	{
		
		for(int i=0;i<1000;i++)
	{
		data[i]='y';
	
	}
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	
	if(huart->Instance==USART1)
	{
		for(int i=1000;i<2000;i++)
	  {
		  data[i]='z';
	  }
	}
}

	void test1(void)
{
	
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_RESET);

	HAL_Delay(500);
	
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_SET);

	HAL_Delay(500);
	
	
}

void test2(void)
{
	
	
	
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
	HAL_Delay(250);
	count++;
	if(count%20==0)
	{
		HAL_UART_Transmit_DMA(&huart1,data,sizeof(data));
	}
	
	
	

}




void MyApp(void)
{
	
	for(int i=0;i<2000;i++)
	{
		data[i]='x';
	
	}
	
	HAL_UART_Transmit_DMA(&huart1,data,sizeof(data));
	
	
 
	while(1)
	{
		
		
		
		test2();
		
		
	
	}


}

