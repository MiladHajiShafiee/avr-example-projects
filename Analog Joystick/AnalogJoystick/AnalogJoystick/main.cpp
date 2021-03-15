/*
 * AnalogJoystick.cpp
 *
 * Created: 2018/08/18 11:41:31 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include "Lcd 2x16.h"
#include "Adc.h"

Adc adc;
Lcd_4_BitMode lcd;

int main(void)
{
	uint16_t AdcValue;
	char buffer[20];
	
	adc.AdcInit(DevidedBy128, Internal);
	lcd.LcdInit();
	
	while(1)
	{
		AdcValue = adc.AdcRead('A', 0)/4;
		sprintf(buffer, "X = %d   ", AdcValue);
		lcd.LcdGoXy(0, 0);
		lcd.LcdString(buffer);
		
		AdcValue = adc.AdcRead('A', 1)/4;
		sprintf(buffer, "Y = %d   ", AdcValue);
		lcd.LcdGoXy(1, 0);
		lcd.LcdString(buffer);
	}
}
