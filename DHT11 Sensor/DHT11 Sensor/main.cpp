/*
 * DHT11 Sensor.cpp
 *
 * Created: 2018/08/24 10:44:26 صـبـح
 * Author : Milad
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include "DHT11 Sensor.h"
#include "Lcd 2x16.h"

Lcd_4_BitMode lcd;


int main(void)
{
	lcd.LcdInit();																				// Initialize LCD
	lcd.LcdClear();																				// Clear LCD
	lcd.LcdGoXy(0,0);																			// Enter column and row position
	lcd.LcdString("Humidity = ");
	lcd.LcdGoXy(1,0);
	lcd.LcdString("Temp = ");

	while(1)
	{
		Request();																				// send start pulse
		Response();																				// receive response
		I_RH = Receive_data();																	// store first eight bit in I_RH
		D_RH = Receive_data();																	// store next eight bit in D_RH
		I_Temp = Receive_data();																// store next eight bit in I_Temp
		D_Temp = Receive_data();																// store next eight bit in D_Temp
		CheckSum = Receive_data();																// store next eight bit in CheckSum
		
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
		{
			lcd.LcdGoXy(0, 0);
			lcd.LcdString("Error");
		}

		else
		{
			lcd.LcdGoXy(0, 11);
			lcd.LcdNum(I_RH, decimal);
			lcd.LcdChar('.');
			
			lcd.LcdNum(D_RH, decimal);
			lcd.LcdChar('%');

			lcd.LcdGoXy(1, 6);
			lcd.LcdNum(I_Temp, decimal);
			lcd.LcdChar('.');
			
			lcd.LcdNum(D_Temp, decimal);
			//lcddata(0xDF);
			lcd.LcdString("C ");
			
			lcd.LcdNum(CheckSum, decimal);
			lcd.LcdChar(' ');
		}

		_delay_ms(10);
	}

}
