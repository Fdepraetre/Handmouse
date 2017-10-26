#include "hardware/gpio.h"

void InitGPIO(void)
{
  // Déclaration de variable locale
  GPIO_InitTypeDef GPIO_InitStruct;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  GPIO_InitStruct.GPIO_Pin   = PIN_LED_1 | PIN_LED_2 | PIN_LED_3 | PIN_LED_4 | PIN_LED_5 ;
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

  GPIO_Init(PORT_LED_1, &GPIO_InitStruct);

}

void SetLed1(void)
{
  GPIOB->BSRR |= 1<PIN_LED_1;
}

void ClearLed1(void)
{
  GPIOB->BRR |= 1<PIN_LED_1;
}

void SetLed2(void)
{
  GPIOB->BSRR |= 1<PIN_LED_2;
}

void ClearLed2(void)
{
  GPIOB->BRR |= 1<PIN_LED_2;
}

void SetLed3(void)
{
  GPIOB->BSRR |= 1<PIN_LED_3;
}

void ClearLed3(void)
{
  GPIOB->BRR |= 1<PIN_LED_3;
}

void SetLed4(void)
{
  GPIOB->BSRR |= 1<PIN_LED_4;
}

void ClearLed4(void)
{
  GPIOB->BRR |= 1<PIN_LED_4;
}

void SetLed5(void)
{
  GPIOB->BSRR |= 1<PIN_LED_5;
}

void ClearLed5(void)
{
  GPIOB->BRR |= 1<PIN_LED_5;
}




