#include <avr/io.h>
#include "led.h"

void LED_init() {
	

    DDRD |= (1 << 6); //OC0A an output
    
}

void toggle_LED(){
	
	PORTD^=(1<<PD6);
}
