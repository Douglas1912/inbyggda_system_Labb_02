#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

#define LED PD6

void set_pwm(uint8_t data);

int main (void) {
	uart_init();
	timer_init();
	LED_init();
	uint8_t i=0;
	
	uint8_t fadeValues[7] = {0,20,80,120,160,200,255};

	while(1){
		
		for(i=0;i<sizeof(fadeValues)/sizeof(fadeValues[0]);i++)
        {
            set_pwm(fadeValues[i]);
            _delay_ms(200);
        }

        for(i=sizeof(fadeValues)/sizeof(fadeValues[0]-1);i>0;i--)
        {
            set_pwm(fadeValues[i]);
            _delay_ms(200);
        }	
	}
	return 0;	
}

void set_pwm(uint8_t data)
{
    OCR0A=data;
}








        