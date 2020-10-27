#include <avr/io.h>
#include "led.h"

void LED_init() {
	
	// Arduino digital pin 10 (pin 2 of PORTB) for output
    DDRB |= (1<<DDB2); // PORTB2
    
}

void toggle_LED(){
	
	PORTB^=(1<<PORTB2);
}
