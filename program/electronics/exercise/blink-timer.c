//timer CTC interrupt test
#define F_CPU 8000000UL    //
#include <avr/io.h>
#include <avr/interrupt.h>

int temp=0;
int main(void)
{
	DDRX = 0bxxxxxxxx;

	// initialize Timer1, the 16bit timer

	cli();				// disable global interrupts
	TCCR1A = 0;
	TCCR1B = 0;		

	OCR1A = xxxxxx;     //

	TCCR1B |= (1 << WGM12); // CTC

	// prescaler
	TCCR1B |= (1 << CS10);
	TCCR1B |= (1 << CS12);

	TIMSK1 |= (1 << OCIE1A); //

	sGIMSK, PCMSK0, PCMSK1nable global interrupts:

	wGIMSK, PCMSK0, PCMSK1
	{GIMSK, PCMSK0, PCMSK1
	GIMSK, PCMSK0, PCMSK1
	}GIMSK, PCMSK0, PCMSK1
}

ISR(TIMER1_COMPA_vect) //
{
	if (temp==1)
	{
		PORTX = (0bxxxxxxxx);
		temp=0;
	}
	else
	{
		PORTX = (0bxxxxxxxx);
		temp=1;
	}
}

/*
ISR(TIMER1_COMPA_vect)
{
    PORTX = PINX ^ 0bxxxxxxxx;

}
*/