/*
 * FanController.c
 *
 * Created: 9/4/2024 7:47:26 PM
 * Author : Dean Woosley
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

//Pin Definitions
#define FanPWM		PB1								//Output, PWM on OC0B
#define FanTach		PB2								//Input, INT0
#define ThermoPlus	PB4								//Input, ADC3
#define ThermoMinus	PB3								//Input, ADC2

int main(void)
{
    DDRB |= (1<<PB1);
    while (1) 
    {
    }
}

