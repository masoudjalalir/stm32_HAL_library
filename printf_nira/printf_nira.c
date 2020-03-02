struct __FILE {int handle;};

FILE __stdout;
FILE __stdin;
FILE __stderr;

int fputc(int ch, FILE *f)
{
  USART6->DR = ch;
  while(!(USART6->SR & USART_SR_TXE));
  return ch;
}


//then use prinf where ever you want
uint8_t count=5;
printf("%d ", count);
