#ifndef UART_H
#define UART_H

#include "stm32f0xx.h"
#include "stm32f0xx_usart.h"

#define PORT_UART_2 PORTA
#define PIN_RX_2 3
#define PIN_TX_2 2
#define UART2_BAUDRATE 115200
#define UART2_WORDLENGTH USART_WordLength_8b
#define UART2_STOPBITS USART_StopBits_1
#define UART2_PARITY USART_Parity_No
#define UART2_MODE USART_Mode_Rx|USART_Mode_Tx 
#define UART2_HARDWARE_FLOW_CONTROL USART_HardwareFlowControl_None

#define UART_ISR_TXE 1<<7



void UartInit(void);
void Uart2_Sendchar(char);
void Uart2_SendString(char*);
void Uart2_SendIntAscii(uint16_t);
static void UART_itoa (uint16_t,char*);

#endif // UART_H
