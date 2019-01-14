# Introduction to interrupts

* [The idea behind interrupts](#the-idea-behind-interrupts)
* [Activating the interrupts](#activating-the-interrupts)
* [Pin change interrupts](#pin-change-interrupts)
* [Supercharged interrupt pins](#supercharged-interrupt-pins)
* [The interrupt routine ISR](#the-interrupt-routine-isr)

## The idea behind interrupts

> You are in your room playing videogames. It is dinner time and **your mum gives you a call to go immediatly**. You stop what you are doing, you eat your dinner and when you finish, you continue playing videogames. In this story, you are a microcontroller. The videogame is the current task. **Your mother is an interrupt**. And dinner is the interrupt subroutine.

We are going to introduce a **powerful piece of hardware** inside the microcontroller, the **interrupts**.

Interrupts are **events that require immediate attention by the microcontroller**. When an interrupt event occurs the microcontroller pauses the current task and attend to the interrupt by executing a subroutine. After that, the microcontroller returns to the task it had paused and continue its normal operation.

## Activating the interrupts

> **Note:** This chapter is based on the attiny 44 microcontroller

We are going to follow a worked example on how to create a simple interrupt.

> **Learn by doing:** Create a new file using, and initialise it with all the information you usually add to the header (author, date, description, license)

For using interrupts you need to include the interrupt library in the header of your C code:

```C
#include <avr/interrupt.h>
```

Also if we want to use interrupts in our application, we have to set (write a 1) in the the bit 7 of the **S**tatus **REG**ister (SREG).

> **Learn by doing:** Check in the datasheet what bit 7 is doing

![status register](img/interrupts/sreg.png)

This can be done either by setting the bit as usual in C.

> **Learn by doing:** How would you set bit 7 to the SREG register in C?

You can alternatively call the instruction SEI (set global interrupt):

```C
sei(); //activates global interrupts
```

## Pin change interrupts

One specific kind of interrupt event is when an **input pin** changes its status, from 0 to 1 or from 1 to 0. They are called **pin change interrups**.

Inside the Attiny44 there are **two** pin change interrupts, one in PORTA and one in PORTB. They will trigger whenever it finds a falling edge or rising edge. So determining if it is a falling edge or rising edge must be done in the interrupt subroutine.
![t44 pins](img/interrupts/t44pin.jpg)

If we want to use them, We have to activate them by setting the corresponding bits in the GIMSK register

![gimsk register](img/interrupts/gimsk.png)

```C
GIMSK |= (1<<PCIE0); //enable pin change interrupt in PORTA (pins PA0 to PA7)
```

> **Learn by doing:** How would you activate pin change interrupts in PORTB?

And then we have to tell the MCU which pin or pins we will be listening to, using the PCMSK0 register.

![pcmsk0 register](img/interrupts/pcmsk0.png)

```C
PCMSK0 |= (1<<PCINT7); //enable PC interrupt in PA7
```

Same for PORTB, we first activate them in the GIMSK register

```C
GIMSK |= (1<<PCIE1); //enable pin change interrupt in PORTB (pins PB0 to PB2)
```

And then we tell the MCU which pins we want to listen using the PCMSK1 register.

![pcmsk1 register](img/interrupts/pcmsk1.png)

## Supercharged interrupt pins

One of the pins of PORTA is a bit special. It is pin **PA0** which can be triggered only at falling, only at rising or only at low level. If we want to use this feature we have to activate the INT0 bit in the GIMSK register

```C
GIMSK |= (1<<INT0); //this would enable INT0 in PA0
```

And set or clear the bits 0 and 1 of the MCUCR (MCU control register)

![mcucr register](img/interrupts/mcucr.png)

Using this table:

![interrupt 0 table](img/interrupts/isc0001.png)

## The interrupt routine ISR

Ok, the interrupt is set and ready. Now what? So far we have activated the desired interrupts using the registers. Depending of which interrupt is triggered (pin change in port A or B or INT0) it will go to a specific subroutine called vector. These are the available vectors in the attiny44:

![vectors table](img/interrupts/vectors.png)

Say we have a button in PA7, connected to ground and an LED in pin PB2 also connected to ground. This would be a subroutine to control the LED with the button using interrupts:

```C
ISR(PCINT0_vect)
{
 if ( PINA & (1<<PINA7) ) // test PINA7 if true then
  PORTB &= ~(1<<PB2); //turn off LED
 else
  PORTB |= (1<<PB2); //Turn on LED
}
```

> **Learn by doing:** Create a new file using, and initialise it with all the information you usually add to the header (author, date, description, license). Write a program that blinks and LED only when you *release* the button.

---
[Back to Summary](../summary.md)
