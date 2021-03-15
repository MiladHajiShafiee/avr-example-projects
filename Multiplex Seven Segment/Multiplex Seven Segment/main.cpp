/*
 * Multiplex Seven Segment.cpp
 *
 * Created: 2018/08/10 2:07:16 عـصـر
 * Author : Milad
 */ 

#define F_CPU 32000000UL

#include <avr/io.h>
#include <util/delay.h>

unsigned char data[4] = {0x3f,0x06,0x5b,0x4f};
void display(void);

int main(void)
{
	DDRA = 0xFF;
    while (1) 
    {
		display();
    }
}

void display(void)
{
	PORTA = data[0];
	PORTA |= (1 << 4);
	_delay_ms(5);
	PORTA &= ~(1 << 4);
		
	PORTA = data[1];
	PORTA |= (1 << 5);
	_delay_ms(5);
	PORTA &= ~(1 << 5);
	
	PORTA = data[2];
	PORTA |= (1 << 6);
	_delay_ms(5);
	PORTA &= ~(1 << 6);
		
	PORTA = data[3];
	PORTA |= (1 << 7);
	_delay_ms(5);
	PORTA &= ~(1 << 7);
}