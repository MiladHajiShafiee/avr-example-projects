/*
 * DHT11_Sensor.h
 *
 * Created: 2018/08/24 10:54:50 صـبـح
 *  Author: Milad
 */ 


#ifndef DHT11 SENSOR_H_
#define DHT11 SENSOR_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define DHT11Pin 6

uint8_t c = 0, I_RH, D_RH, I_Temp, D_Temp, CheckSum;

void Request()																	/* MicroController send start pulse/request */
{
	DDRD |= (1 << DHT11Pin);
	PORTD &= ~(1 << DHT11Pin);													/* set to low pin */
	_delay_ms(20);																/* wait for 20ms */
	PORTD |= (1 << DHT11Pin);													/* set to high pin */
}

void Response()																	/* receive response from DHT11 */
{
	DDRD &= ~(1 << DHT11Pin);
	while(PIND & (1 << DHT11Pin));
	while((PIND & (1 << DHT11Pin)) == 0);
	while(PIND & (1 << DHT11Pin));
}

uint8_t Receive_data()															/* receive data */
{
	for (uint8_t q = 0; q < 8; q++)
	{
		while((PIND & (1 << DHT11Pin)) == 0);									/* check received bit 0 or 1 */
		_delay_us(30);
		if(PIND & (1 << DHT11Pin))												/* if high pulse is greater than 30ms */
		{
			c = (c << 1)|(0x01);												/* then its logic HIGH */
		}
		else																	/* otherwise its logic LOW */
		{
			c = (c << 1);	
		}
		
		while(PIND & (1 << DHT11Pin));
	}
	return c;
}

#endif /* DHT11 SENSOR_H_ */