#include "hardware/uart.h"

void UartInit(void)
{

   GPIO_InitTypeDef GPIO_InitStruct;
   USART_InitTypeDef USART_InitStruct;
   NVIC_InitTypeDef NVIC_InitStruct;

   GPIO_InitStruct.GPIO_Pin   = PIN_RX_2 | PIN_TX_2;
   GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF;
   GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

   GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_0);
   GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_0);

   GPIO_Init(GPIOB, &GPIO_InitStruct);

   USART_InitStruct.USART_BaudRate = UART2_BAUDRATE;
   USART_InitStruct.USART_WordLength = UART2_WORDLENGTH;
   USART_InitStruct.USART_StopBits = UART2_STOPBITS;
   USART_InitStruct.USART_Parity = UART2_PARITY;
   USART_InitStruct.USART_Mode = UART2_MODE;
   USART_InitStruct.USART_HardwareFlowControl = UART2_HARDWARE_FLOW_CONTROL;

   USART_Init(USART2, &USART_InitStruct);
   USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

   NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
//   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
//   NVIC_InitStruct.NVIC_IRQChannelSubPriority        = 0;
   NVIC_InitStruct.NVIC_IRQChannelCmd                = ENABLE;
   NVIC_Init(&NVIC_InitStruct);
   USART_Cmd(USART2, ENABLE);

}


void Uart2_sendchar(char c)
{
  uint16_t timeout = 0;
  while((!(USART2->ISR & USART_ISR_TXE) && timeout <1000))
  {
    timeout++;
  }
  if( timeout <1000)
  {
    USART2->TDR = (c & (uint8_t)0x1F);
  }
}

void Uart2_sendString(char *c)
{
  while(*c)
  {
    while(!(USART2->SR & 0x00000040));
    Uart2_sendchar(*c);
    *c++;

  }
  while(!(USART2->SR & 0x00000040));
}


void Uart2_SendIntAscii(uint16_t v)
{ 
  char s[200]={0};

  USART_itoa(v,s); 
  Uart2_sendString(s);

  return;
}

static void UART_itoa (uint16_t n,char s[])
 {
   uint16_t i, sign;

   if ((sign = n) < 0)  /* record sign */
     n = -n;          /* make n positive */
   i = 0;
   do {       /* generate digits in reverse order */
     s[i++] = n % 10 + '0';   /* get next digit */
   } while ((n /= 10) > 0);     /* delete it */
   if (sign < 0)
     s[i++] = '-';
   s[i] = '\0';
   reverse(s);
 }
