//--------------------------------------------------------------
// Define aliases
#define F_CPU 16000000      // Microcontroller frequency

//Include header librarys
#include <avr/io.h>         // Definitions of the specified component
#include <util/delay.h>     // Use delay functions
#include <avr/interrupt.h>  // Use interruptions
#include <avr/pgmspace.h> 	// Write data to flash memory
#include <stdio.h>			// Use sprintf functions
#include <math.h>			// Use math functions
#include <stdbool.h>		// Use boolean variables
#include <stdint.h>

// Global variables
volatile bool a, b;
volatile unsigned int x[3] = {0};
volatile float ref, source, output, error, duty, fis_duty = 0;

// Include header files
#include "LCD.h" 			// Use the LCD
#include "ADC.h"			// Use the ADC
#include "lcd_setup.h"      // Setup and use the LCD
#include "sensor_sub.h"     // Sensor subsystem
#include "error_sub.h"      // Error subsystem
#include "lut_setup.h"      // Control setup and subsystem
#include "mode_setup.h"     // Mode setup and subsystem
#include "pwm_setup.h"		// PWM setup
#include "timer_setup.h"	// Time interruption setup
//--------------------------------------------------------------
int main(void){
	// Initializes peripherals
	lcd_setup();
	inicializa_ADC();
	mode_setup();
	pwm_setup();
	timer_setup();
	
    // Turn on interruptions
    sei();
    
    // Initializes system
	sensor_sub();
	error_sub();
	fis_output();
	mode_sub();
//------------------------------
    while(1){
	lcd_sub();
	}
//------------------------------
}
//--------------------------------------------------------------
ISR(TIMER2_COMPA_vect){
	sensor_sub();
	error_sub();
	fis_output();
	mode_sub();
}
//--------------------------------------------------------------