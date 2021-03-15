/*
 * Adc.h
 *
 * Created: 2018/07/29 7:33:27 صـبـح
 *  Author: Milad
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "IORegisters.h"

enum FrequencyDivision {
	DevidedBy2, DevidedBy4,
	DevidedBy8, DevidedBy16,
	DevidedBy32, DevidedBy64,
	DevidedBy128
	};
	
enum VoltageReferance {
	AREF, AVcc, Internal
	};


class Adc
{
	public:
	
	void AdcInit(FrequencyDivision ADCSRAFrequency ,VoltageReferance Vref);
	
	uint16_t AdcRead(unsigned char adcPort ,uint8_t AdcChannel);
	
	};


#endif /* ADC_H_ */