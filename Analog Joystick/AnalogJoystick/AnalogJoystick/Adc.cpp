/*
 * Adc.cpp
 *
 * Created: 2018/07/29 7:33:10 صـبـح
 *  Author: Milad
 */ 

#include "IORegisters.h"
#include "Adc.h"

Registers IORegister;

void Adc::AdcInit(FrequencyDivision ADCSRAFrequency, VoltageReferance Vref)
{
	ADCSRA |= (1 << ADSC);
	switch (ADCSRAFrequency)
	{
		case DevidedBy2:
		ADCSRA = (1 << ADEN)|(1 << ADPS0);
		break;
		case DevidedBy4:
		ADCSRA =  (1 << ADEN)|(1 << ADPS1);
		break;
		case DevidedBy8:
		ADCSRA =  (1 << ADEN)|(1 << ADPS0)|(1 << ADPS1);
		break;
		case DevidedBy16:
		ADCSRA =  (1 << ADEN)|(1 << ADPS2);
		break;
		case DevidedBy32:
		ADCSRA =  (1 << ADEN)|(1 << ADPS0)|(1 << ADPS2);
		break;
		case DevidedBy64:
		ADCSRA =  (1 << ADEN)|(1 << ADPS1)|(1 << ADPS2);
		break;
		case DevidedBy128:
		ADCSRA =  (1 << ADEN)|(1 << ADPS0)|(1 << ADPS1)|(1 << ADPS2);
		break;
	}
	
	if (Vref == AREF)
	{
		ADMUX &= ~(1 << REFS0);
		ADMUX &= ~(1 << REFS1);
	}
	else if (Vref == AVcc)
	{
			ADMUX |= (1 << REFS0);
			ADMUX &= ~(1 << REFS1);
	}
	else if (Vref == Internal)
	{
		ADMUX |= (1 << REFS0);
		ADMUX |= (1 << REFS1);
	}
	
}

uint16_t Adc::AdcRead(unsigned char adcPort, uint8_t AdcChannel)
{
	IORegister.DdrRegisters(adcPort , AdcChannel , 0);
	ADMUX = ADMUX|(AdcChannel & 0x0f);
	ADCSRA = (1 << ADSC)|(1 << ADEN);
	while (ADIF == 0);
	ADCSRA |= (1 << ADIF);
	return ADCW;
}
