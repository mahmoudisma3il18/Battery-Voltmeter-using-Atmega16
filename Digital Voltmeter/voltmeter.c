/*
 * voltmeter.c
 *
 * Created: 3/26/2023 5:29:51 PM
 *  Author: Mahmoud Ismail
 */ 


#include "voltmeter.h"

float Voltmeter_getVoltage() {
	
	uint16_t adc_value = ADC_readChannel(SENSOR_CHANNEL_ID); // Reads Value of ADC
	
	float voltage;
	
	voltage = (((float)adc_value*50.0)/(1023));
	
	return voltage;
	
	
}