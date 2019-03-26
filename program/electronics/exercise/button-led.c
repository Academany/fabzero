#define F_CPU 8000000UL
#include <avr/io.h>

// This program should turns LED ON when the button is pressed

int main (void)
{

    DDRX |= (1 << PXX); // led config

    DDRX &= ~(1 << PXX); // switch config

    PORTX = 0bxxxxxxxx;  // pull-up for switch pin


    while(1) 
    {
        if (PINX & 0bxxxxxxxx)
            PORTX = 0bxxxxxxxx;
        else
            PORTX = 0bxxxxxxxx;
    }
}


// now try doing it with pinchange interrupts
// CLUE look for the following registers 
// GIMSK, PCMSK0, PCMSK1
// look for interrupt vectors ISR(PCINTX_vect)
//
//
// also try to do this with INT0, the button we have is connected to a special pin. 