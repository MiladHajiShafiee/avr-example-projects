/*
 * SPI.cpp
 *
 * Created: 2018/08/02 9:21:43 صـبـح
 *  Author: Milad
 */ 

 #include <avr/io.h>
 #include "SPI.h"
 
 
void Spi::SSEnable(void)
{
	PORTB &= ~(1 << SS);
}

void Spi::SSDisable(void)
{
	PORTB |= (1 << SS);
}

 void Spi::MasterInit(void)
 {
	 DDRB = (1 << SCK)|(1 << MOSI)|(1 << SS)|(1 << RST)|(1 << DC);
	 PORTB |= (1 << RST);		
	 DDRB &= ~(1 << MISO);
	 PORTB |= (1 << SS);
	 SPCR = (1 << SPE)|(1 << MSTR)|(1 << SPR0);
 }
 
 void Spi::Write(char data)
 {
	 char flushBuffer;
	 SPDR = data;
	 while(!(SPSR & (1 << SPIF)));
	 flushBuffer = SPDR;
 }
 
 char Spi::Read(void)
 {
	 SPDR = 0xFF;
	 while (!(SPSR & (1 << SPIF)));											// Wait till reception complete
	 return (SPDR);															// Return received data
 }
 
 void Spi::SlaveInit(void)
 {
	
	DDRB &= ~((1 << SCK)|(1 << MOSI)|(1 << SS));							// Make MOSI, SCK, SS as input pins				
	DDRB |= (1 << MISO);													// Make MISO pin as output pin */
	SPCR = (1 << SPE);														// Enable SPI in slave mode */
 }
 