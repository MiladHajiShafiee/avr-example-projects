/*
 * Nokia5110 Graphical Display.cpp
 *
 * Created: 2018/08/24 7:48:53 صـبـح
 * Author : Milad
 */ 

#include <avr/io.h>
#include "Nokia5110 Graphical Display.h"
#include "SPI.h"

NokiaDisplay Nlcd;
Spi spi;

int main()
{
	spi.MasterInit();
	Nlcd.Init();
	Nlcd.Clear();
	Nlcd.SetXy(0x40,0x80);
	Nlcd.Image(AnimKid);
	while(1)
	return 0;
}
