/*
 * RTC ( DS1307 ).cpp
 *
 * Created: 2018/08/21 7:59:38 صـبـح
 * Author : Milad
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "RTC.h"
#include "Lcd 2x16.h"

Lcd_4_BitMode lcd;

int main(void)
{
	char buffer[20];
	char* days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
	i2c.MasterInit(DevidedBy1);
	lcd.LcdInit();
	
    while (1) 
    {
		RTCReadClock(0);
		if (hour & TimeFormat12)
		{
			sprintf(buffer, "%02x:%02x:%02x  ", (hour & 0b00011111), minute, second);
			if(IsItPM(hour))
			strcat(buffer, "PM");
			else
			strcat(buffer, "AM");
			lcd.LcdStringXy(0, 0, buffer);
		}
		
		else
		{
			sprintf(buffer, "%02x:%02x:%02x  ", (hour & 0b00011111), minute, second);
			lcd.LcdStringXy(0, 0, buffer);
		}
		RTCReadCalendar(3);
		sprintf(buffer, "%02x/%02x/%02x %3s ", date, month, year, days[day-1]);
		lcd.LcdStringXy(1, 0, buffer);
    }
}

