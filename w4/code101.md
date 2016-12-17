# Introduction to embedded C programming

In this section we are going to learn to program an attiny44 using AVR-GCC toolchain in C language. Programming is a huge topic. It will take long time to master.

## I know Arduino scripting language. I don't need C
Please watch this video https://www.youtube.com/watch?v=ERY7d7W-6nA

## The datasheet
The first thing you should know about embedded programming is that **you cannot program a microcontroller without reading the datasheet** of that specific microcontroller.

> Download the [Attiny 44 Datasheet](http://www.atmel.com/images/doc8006.pdf) and browse through it.

## Setting up AVR-GCC Toolchain on Linux
For writing code you just need a text editor, like atom. AVR-GCC is a toolchain that will help you with the software development process, but doesn’t do anything about burning the final executable (the hex file) to the microcontroller. For that we need to install **AVR D**ownloader **U**ploa**DE**r (avrdude)

`sudo apt install avrdude gcc-avr binutils-avr avr-libc`

## The basic idea
A microcontroller has a number of pins. Some pins have a fixed function and cannot be changed, like VCC or GND. The rest of the pins and can be configured as inputs or outputs.

By default pins are configured as input

https://www.arduino.cc/en/Tutorial/DigitalPins

## Registers
Say hello to something it will be

## Hello world program


## The button and LED program

```C
#define F_CPU 1000000UL
#include <avr/io.h>

// This program turns LED ON when the button is pressed

int main (void)
{

  DDRB |= (1 << PB2);
  // set PB2 as output in DDRB

  DDRA &= ~(1 << PA3);
  // set PA3 as input in DDRA

  PORTA = 0B00001000;
  // SET PULL UP RESISTOR IN PA3

 while(1) {
   if (testbit(PINA,PA3))  

   PORTB = 0b00000000;
   // set PB2 low to turn led off

   else

   PORTB = 0b00000100;
   // set PB2 high to turn led on
        }
}
```
## Bitwise operations

## Macros
```C
#define setbit(register, bit)   (register) |=  (1 << (bit))
#define clearbit(register, bit) (register) &= ~(1 << (bit))
#define testbit(register, bit)  (register) &   (1 << (bit))
```
```C
setbit(PORTA, PA0)
clearbit(PORTB, PB3)
testbit (PORTA, PA2)
```
This makes your code much easier to understand. The precompiler will substitute the macros out at compile time and you will be left with the exact same code in your AVR.

## Compiling the program

## The Makefile

http://www.ladyada.net/learn/avr/avrdude.html

## The programmer


Do not start from scratch. Start by editing an existing program.



---
[Back to Summary](../summary.md)
