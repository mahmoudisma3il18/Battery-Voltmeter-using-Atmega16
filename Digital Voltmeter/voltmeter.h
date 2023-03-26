/*
 * voltmeter.h
 *
 * Created: 3/26/2023 5:30:03 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef VOLTMETER_H_
#define VOLTMETER_H_

/*----------------------------  Includes ---------------------------------*/

#include "ADC.h"


/*------------------------------ Defines --------------------------------*/

#define SENSOR_CHANNEL_ID     Channel6_ID
#define REF_VOLTAGE           5.0
#define ADC_MAX_VALUE         1023


/*---------------------------------- Function Prototypes --------------------*/

/* 
Description : Returns Voltage Reading
*/
float Voltmeter_getVoltage(void);





#endif /* VOLTMETER_H_ */