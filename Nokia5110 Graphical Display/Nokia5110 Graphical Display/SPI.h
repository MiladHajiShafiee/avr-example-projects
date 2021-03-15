/*
 * SPI.h
 *
 * Created: 2018/08/02 9:21:22 صـبـح
 *  Author: Milad
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define MOSI 5																			/* Define SPI bus pins */
#define MISO 6
#define SCK 7
#define SS 4
#define RST 0
#define DC 1																			/* Define Slave disable */

class Spi
{
	public:
	
	void SSEnable(void);
	
	void SSDisable(void);
	
	void MasterInit(void);
	
	void Write(char data);
	
	char Read(void);
	
	void SlaveInit(void);
	
	};



#endif /* SPI_H_ */