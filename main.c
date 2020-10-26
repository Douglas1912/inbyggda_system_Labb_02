#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

uint8_t number = 1;

void main (void) {
	uart_init();
	timer_init();
	LED_init();

	while(1)
    {
	
        // check if the timer count reaches 156
        if (TCNT0 >= OCR0A)
        {
            TCNT0 = 0;            // reset counter
			number++;
		}
		if(number >= 10){
			LED_on();
			number = 0;			
		}		
	}
}
