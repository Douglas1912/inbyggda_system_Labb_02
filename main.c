#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

#define LED PORTB2

int main (void) {
	uart_init();
	timer_init();
	LED_init();
	uint8_t timerOverflowCount=0;

	while(1){
		
		if (TIFR0 & (1 << OCF0A )) {
			
			timerOverflowCount++;
			TIFR0 |= (1 << OCF0A );	//clear timer0 overflow flag
			
			if (timerOverflowCount>=10){
				
				PORTB^=(1<<LED);	
				timerOverflowCount=0;
			}
		}			
	}
}








        