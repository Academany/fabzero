# Introduction to interrupts
We are going to introduce a powerful piece of hardware inside the microcontroller, the interrupts.

Interrupts are events that require immediate attention by the microcontroller. When an interrupt event occurs the microcontroller pause its current task and attend to the interrupt by executing a subroutine. After that, the microcontroller returns to the task it had pause and continue its normal operation.

## Activating the interrupts
For using interrupts you need to add the interrupt library in the header of your C code:

`#include <avr/interrupt.h>`

Also if we want to use interrupts in our application first we have to set a logic one in the the bit 7 of the Status REGister (SREG).

![](img/interrupts/sreg.png)

This can be done either by setting the bit as usual in C or using the instruction SEI (set global interrupt):

`sei(); //activates global interrupts`

## Pin change interrupts
Inside the Attiny44 there are pin change interrupts in PORTA and PORTB. They will trigger both at falling and rising edge, so determining if it is a falling edge or rising edge must be done in the interrupt subroutine.
![](img/interrupts/t44pin.jpg)

If we want to use them, We have to activate them by setting the corresponding bits in the GIMSK register

![](img/interrupts/gimsk.png)

`GIMSK |= (1<<PCIE0); //enable pin change interrupt in PORTA (pins PA0 to PA7)`

And then we have to tell the MCU which pin or pins we will be listening to, using the PCMSK0 register.

![](img/interrupts/pcmsk0.png)

`PCMSK0 |= (1<<PCINT7); //enable PC interrupt in PA7`

Same for PORTB, we first activate them in the GIMSK register

`GIMSK |= (1<<PCIE1); //enable pin change interrupt in PORTB (pins PB0 to PB2)`

And then we tell the MCU which pins we want to listen using the PCMSK1 register.

![](img/interrupts/pcmsk1.png)

## Supercharged interrupt
One of the pins of PORTA is a bit special. It is pin PA0 which can be triggered just at falling, rising or low level. If we want to use this feature we have to activate the INT0 bit in the GIMSK register

`GIMSK |= (1<<INT0); //this would enable INT0 in PA0`

And set or clear the bits 0 and 1 of the MCUCR (MCU control register)

![](img/interrupts/mcucr.png)

Using this table:

![](img/interrupts/isc0001.png)

## The interrupt routine ISR
So far we have activated the desired interrupts using the registers. Depending of which interrupt is triggered (pin change in port A or B or INT0) it will go to a specific subroutine called vector. These are the vectors:

![](img/interrupts/vectors.png)

Say we have a button in PA7, connected to ground and an LED in pin PB2 also connected to ground. This would be a subroutine to control the LED with the button using interrupts:
```
ISR(PCINT0_vect)
{
 if ( PINA & (1<<PINA7) ) // test PINA7 if true then
  PORTB &= ~(1<<PB2); //turn off LED
 else
  PORTB |= (1<<PB2); //Turn on LED
}
```

---
[Back to Summary](../summary.md)
