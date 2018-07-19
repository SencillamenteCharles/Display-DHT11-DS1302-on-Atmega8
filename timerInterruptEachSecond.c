/*
 * timerInterruptEachSecond.c
 *
 * Created: 11/06/2018 06:40:50 p. m.
 *  Author: José Rodrigo
 */ 
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <avr/io.h>

void set_timer1();
int main(void)
{
	set_timer1();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
void set_timer1()
{
	sei();//enabling all interrupt sources
	//setting timer 1 of 16 bits in normal mode at prescaler of 8 from CPU 
	TCCR1A=0;//normal operation mode
	TCCR1B=0b00000010;//prescaler selection on first LSB bits, 
	TIMSK|=1<<TOIE1;//enabling Timer 1 overflow interrupt
	DDRC|=1<<PINC2;
	TCNT1=3035;//62,500 ticks left of 65535, meaning that an ovrflw appears each half second
}

ISR (TIMER1_OVF_vect)
{
	PORTC^=1<<PINC2;
	TCNT1=3035;
}	