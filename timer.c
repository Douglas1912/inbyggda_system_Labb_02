#include <avr/io.h>

#include "timer.h"

void timer_init() { 

    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode

    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode

	
    TCCR0B |= (1 << CS01)|(1 << CS00);
    // set prescaler to 64 and starts PWM
}

