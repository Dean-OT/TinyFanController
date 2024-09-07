/*
 * FanController.c
 *
 * Created: 9/4/2024 7:47:26 PM
 * Author : Dean Woosley
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Pin Definitions
#define FanPWM		PB1								//Output, PWM on OC1A
#define FanTach		PB2								//Input, INT0
#define ThermoPlus	PB4								//Input, ADC3
#define ThermoMinus	PB3								//Input, ADC2

//Global Variables
volatile int i = 0;

ISR (INT0_vect)
{
	i++;
}

int main(void)
{
	//Setting up the pins
    DDRB |= (1<<FanPWM);
	PORTB |= (1<<FanTach) | (1<<FanPWM);
	
	//INT0 interrupt enable
	MCUCR |= (1<<ISC01);
	GIMSK |= (1<<INT0);
	
	//8MHz/2/(OCR1C+1) = 25kHz when OCR1C = 159
	TCCR1 |= (1<<PWM1A) | (1<<COM1A1) | (1<<CS11);
	GTCCR = 0x00;
	OCR1C = 159;
	OCR1A = 159;
	
	sei();
	
	while(1)
	{
		if (i<OCR1C+1)
		{
			OCR1A = i;
		}
		else if (i> OCR1C+1)
		{
			i=0;
			OCR1A = i;
		}
	}
}

