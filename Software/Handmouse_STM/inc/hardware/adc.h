#ifndef ADC_H
#define ADC_H

#include "stm32f0xx.h"
#include "stm32f0xx_adc.h"

void ADC_Init();
void ADC_MspInit();
void ADC_StartConversion();



#endif # ADC_H