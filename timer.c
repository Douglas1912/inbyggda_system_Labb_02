#include <avr/io.h>

#include "timer.h"

void timer_init() { 

	/* CTC mode */
	TCCR0A |= (1 << WGM01);    
	
	// set up timer with prescaler = 1024 Clock Select Bits,
	//start counting every 1024 MCs-machine cycle
    TCCR0B |= (1 << CS02)|(1 << CS00);
  
    // initialize counter
    TCNT0 = 0;
	
	//output compare-värde(156) = 16Mhz/1024 = 16000000/1024 = 15625Hz
	// = 15625/100Hz, if we want 10ms in hertz what is 100hz
	OCR0A = 156;
}

