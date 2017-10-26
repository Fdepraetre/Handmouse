#ifndef GPIO_H
#define GPIO_H

#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"

#define PORT_LED_1 (GPIOB)
#define PIN_LED_1 ((uint8_t) 3)

#define PORT_LED_2
#define PIN_LED_2 ((uint8_t) 4)

#define PORT_LED_3
#define PIN_LED_3 ((uint8_t) 5)

#define PORT_LED_4
#define PIN_LED_4 ((uint8_t) 6)

#define PORT_LED_5
#define PIN_LED_5 ((uint8_t) 7)


void InitGPIO(void);

void SetLed1(void);
void ClearLed1(void);
void SetLed2(void);
void ClearLed2(void);
void SetLed3(void);
void ClearLed3(void);
void SetLed4(void);
void ClearLed4(void);
void SetLed5(void);
void ClearLed5(void);


#endif // GPIO_H
