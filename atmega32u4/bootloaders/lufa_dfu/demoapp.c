/*
 * demoapp.c
 *
 * Created: 29/05/2013 3:20:43 PM
 *  Author: Stanley Lio
 */ 


#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 255;
	DDRD = 255;
	
    while(1)
    {
		PORTB = 0;
		PORTD = 255;
		_delay_ms(1000);
		PORTB = 255;
		PORTD = 0;
		_delay_ms(1000);
    }
}