/*
 * Digital Voltmeter.c
 *
 * Created: 3/25/2023 3:01:45 AM
 * Author : Mahmoud Ismail
 */ 


/*------------------------------------- Includes ------------------------------------*/

#include "lcd.h"
#include "voltmeter.h"
#include <stdlib.h>
#include <math.h>

/*------------------------------- Functions ----------------------------------------*/
int main(void)
{
    /* Replace with your application code */
	
	LCD_init(); // Intiliaze LCD
	
	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF); // TurnOff LCD Cursor Blinking
	
	ADC_ConfigType ADC_ConfigStruct = {F_CPU_8,AREF}; // Struct For ADC configurations
		
	ADC_init(&ADC_ConfigStruct); // Intiliaze ADC
	
	float voltage ; 
	
	uint8_t array_of_voltage[4]; // Array of chars to hold float value of voltage

		
    while (1) 
    {
		
		voltage = Voltmeter_getVoltage(); // Reads value from ADC and convert it to voltage
		
		dtostrf(voltage, 4, 1, array_of_voltage); // Convert Float to array of chars to Display on LCD
		
		if (voltage == 0.0)
		{
			LCD_displayStringRowColumn(0,2,"Disconnected");
		}
		else
		{
			LCD_displayStringRowColumn(0,2,"Connected  "); // Clear Row 1
			LCD_displayStringRowColumn(1,0,"Voltage = ");
			LCD_displayString(array_of_voltage); // Show Voltemer Reading
			LCD_displayString("  "); // To clear display after Voltage Value
		}
    }
}

