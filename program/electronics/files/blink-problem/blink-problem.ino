/* Blink an external LED during 5 seconds
 *  and at the same time program the button 
 *  to turn on the internal LED.
 *  
 *  External LED in PB1
 *  Internal LED in PB5
 *  External button in PD7
 *  
 *  by Francisco Sanchez
 *  Wednesday 7h of August 2019
 */

#include <avr/io.h>
#include <util/delay.h>

int main (void) {

// Declare inputs and outputs

DDRB |= (1<<PB1); // PB1 is output
DDRB |= (1<<PB5); // PB5 is output
DDRD &= ~(1<<PD7); // PD7 is input

// Activate pull up resistor

PORTD |= (1<<PD7); // pull up activated

  while(1) {

PORTB |= (1<<PB1); // LED on
_delay_ms(5000);
PORTB &= ~(1<<PB1);
_delay_ms(5000);

if (PIND & (1<<PD7);
  PORTB &= ~(1<<PB5);
 else
  PORTB |= (1<<PB5);
    
  }
 }

 
