#include "main.h"
#include "MyApp.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;


/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

void Log(char* log)
{
	HAL_UART_Transmit(&huart1,(uint8_t*)log,strlen(log),100);

}

void test1(void)
{
	char  buff[30];
	int   counter=123;
	float floatval=123.456;
	char  charval='M';
	char* stringval="HELLOWORLD";
	uint32_t HEXVAL=0x1234;
	
	
	printf("int :%d\n\r",counter);
	printf("floatval :%.1f\n\r",floatval);
	printf("char :%c\n\r",charval);
	printf("stringval :%s\n\r",stringval);
	printf("int :%04d  floatval :%.1f\n\r",counter,floatval);
	printf("floatval :%f\n\r",floatval);
	printf("percent %% // \\");
	printf("HEXVAL : %02x",HEXVAL);
	printf("HEXVAL : %X",HEXVAL);

	
	//sprintf(buff,"counter : %d",counter);
	//Log(buff);
	
	
	//Log("masoud  \\ %% \n\r");
	
	
	
	
	
}


void test2(void)
{
	
}


void MyApp(void)
{
	
	while(1)
	{
		test1();
	//test2();
	
	}		

		

}
			
