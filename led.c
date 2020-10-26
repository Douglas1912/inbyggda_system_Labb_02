#include <avr/io.h>
#include "led.h"

void LED_init() {
	
	// Arduino digital pin 10 (pin 2 of PORTB) for output
    DDRB |= (1<<DDB2); // PORTB2
    
}

void LED_on(){
	
	PORTB^=(1<<PORTB2);
}
