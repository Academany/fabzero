# Assembly

![spartans](./img/assembly/sparta.jpg)

* [Why Assembly](#why-assembly)
* [Assembler](#assembler)
* [Instruction set](#instruction-set)
* [Datasheets](#datasheets)
* [Inputs and Outputs](#inputs-and-outputs)
* [Timing](#timing)
  * [Determining the period](#determining-the-period)
  * [Worked example](#worked-example)
  * [Timers and counters](#timers-and-counters)
* [Assembly Instruction Set](#assembly-instruction-set)
  * [Data Transfer Instructions](#data-transfer-instructions)
  * [Arithmetic Instructions](#arithmetic-instructions)
  * [Logic Instructions](#logic-instructions)
  * [Compare Instructions](#compare-instructions)
  * [Rotate and Shift Instructions](#rotate-and-shift-instructions)
* [Button-LED example](#button-led-example)
* [The Stack](#the-stack)
* [Macros](#macros)
* [Inline Assembly in C](#inline-assembly-in-c)
* [LED blink delay example](#led-blink-delay-example)
* [Programming Structures in Assembly](#programming-structures-in-assembly)
  * [Translate an If-then-else statement to AVR assembly code](#translate-an-if-then-else-statement-to-avr-assembly-code)
  * [Translate a for statement to AVR assembly code](#translate-a-for-statement-to-avr-assembly-code)
  * [Translate a switch statement to AVR assembly code](#translate-a-switch-statement-to-avr-assembly-code)
  * [Translate a while statement to AVR assembly code](#translate-a-while-statement-to-avr-assembly-code)

## Why Assembly

At some point you will need to be in control of some parts of the hardware inside the microcontroller, or shrink the size of the program, or make it more efficient, so you will need to go for Assembly. Each line in assembly translate to a single instruction. Assembly instructions are shorter and more intuitive to remember.

**First warning: Assembly is not for everyone. It is only for the brave**.
In Assembly, you are directly controlling the hardware. This is why I like it the most, because that means you also learn about how the hardware you are controlling works.

C _vs_ Assembly is like going somewhere by Bus vs driving a car. Bus is more comfortable but you cannot go where you want when you want. If you want to go where the Bus service is not reaching or at a different time you have to drive a car. But driving a car requires you to steer the wheel yourself, brake and accelerate yourself, check the rpm, the water levels, and many other things. But these are awesome things, don't they?

Finally, you could even [get a job](http://www.theregister.co.uk/2015/10/31/brush_up_on_your_fortran/) at NASA if you learn Assembly.

## Assembler

You need an assembler compiler to convert the `.asm` file to a `.hex` file that will be uploaded to the microcontroller. I use [gavrasm](http://www.avr-asm-tutorial.net/gavrasm/index_en.html), a command line tool available for windows and linux. Just download and unzip it. If you want the program to be available from everywhere in the terminal move it to `/usr/local/bin`:

`$ sudo mv gavrasm /usr/local/bin`

## Instruction set

[8 bit AVR Instruction set](http://academy.cba.mit.edu/classes/embedded_programming/doc0856.pdf)
[AVR Assembler user guide](http://academy.cba.mit.edu/classes/embedded_programming/doc1022.pdf)

## Datasheets

Programming in assembly requires a big knowledge of the hardware since the instructions control this hardware directly. All the information about the microcontroller can be found in the datasheet. Some important microcontroller datasheets for Fab Academy are:

* [attiny44](files/datasheets/attiny44.pdf)
* [attiny45](files/datasheets/attiny45.pdf)
* [atmega328](files/datasheets/atmega328.pdf)

## Inputs and Outputs

Here is a good resource shared by [Sibu](http://archive.fabacademy.org/archives/2016/fablabtrivandrum/students/281/index.html) in order to understand ports and pins in the AVR microcontroller family and how to control them with the 3 registers DDRx,PORTx and PINx.

[ATMEL AVR Tutorial 2: How to access Input/Output Ports?](http://www.elecrom.com/2008/02/12/avr-tutorial-2-avr-input-output/)

## Timing

One of the biggest advantages of assembly over other languages is the ability to precisely control time. It is even possible to actually predict how much time a program will take to execute.

### Determining the period

Since we know the frecuency at which the MCU is running we can determine the period. For instance, for a MCU running at `f = 8 MHz` (8 million cycles per second), each cycle will take `T = 1/f`, that is, the period T is `T = 1/8000000 = 0.000000125 s = 0.125 us = 125 ns`. The following are common frecuency/period in AVR microcontrollers.

| Frecuency | Period (us) | Period (ns) |
| --------- | ----------- | ----------- |
| 1 MHz     | 1           | 1000        |
| 8 MHz     | 0.125       | 125         |
| 16 MHz    | 0.0625      | 62.5        |
| 20 MHz    | 0.05        | 50          |

So at 20MHz an instruction that takes one cycle in assembly is going to take 50 ns, and this is going to be as exact as your clock source, which to recall it is:

| Clock source           | Precision |
| ---------------------- | --------- |
| Internal RC            | 10%       |
| Internal RC Calibrated | 1%        |
| Resonator              | 0.5 %     |
| Crystal                | 50 ppm    |

### Worked example

Let's see how long int takes to execute this piece of assembly code:

```asm
LDI   R16, 255
LDI   R17, 100
ADD   R17, R16
MOV   R20, R17
```

We have 3 different instructions here `LDI`, `ADD` and `MOV`. If we look at the above [AVR Assembler user guide](http://academy.cba.mit.edu/classes/embedded_programming/doc1022.pdf), from section 4-5 onwards we can see that these instructions take exactly 1 cycle to execute each one. So this piece of code takes 4 cycles in total.

Since we know the period of a cycle, it is just a matter of multiplying `4 cycles*T`. So at 20 MHz this piece of code takes 200 ns.

### Timers and counters

The following is a video from [Basic and Default Usage of a Timer and Counter and The Microcontroller Clock](https://www.newbiehack.com/TimersandCountersDefaultandBasicUsage.aspx) explaining the basics about timers and counters.

<iframe width="853" height="480" src="https://www.youtube-nocookie.com/embed/Tj6xGtwOlB4?rel=0&amp;controls=0&amp;showinfo=0" frameborder="0" allowfullscreen></iframe>

## Assembly Instruction Set

### Data Transfer Instructions

* `mov dest,orig` copies the value of `orig` register to `dest` register

### Arithmetic Instructions

* `DEC reg` decrease 1 the value of the register
* `ADD reg1,reg2` adds the value of reg1 to reg2

### Logic Instructions

* `AND`
* `OR`
* `EOR`

### Compare Instructions

* `CPI value1,value2` compares 2 values and results in 0 (no equal) or different from 0 (equal)

### Rotate and Shift Instructions

* `SBI reg,bit` sets a bit in a register
* `CBI reg,bit` clears a bit in a register
* `BRNE label` jumps to the specified label if the result of `cpi` is 0
* `LDI reg,value` loads the specified value in the register
* `CLI reg` clears the entire register
* `JMP label` jumps to a certain label
* `RJMP label` jumps to a label at a maximum distance of -+ 2k words

## Button-LED example

```asm
; buttonled.asm
;
; Fab Academy
; February 2016
; by Francisco Sanchez
; CC-BY-SA 4.0 License
;
; This program turns on the LED of a helloworld board when the button is pressed

.device attiny44                ; defines which device to assemble for
.org 0		                    ; sets the programs origin
          SBI   DDRA,7          ; sbi reg,bit Sets a bit of a register.
                                ; Setting DDRA bit 7 makes pin PA7 a (digital) output
          CBI   DDRB,3          ; sets PB3 as input
          SBI   PORTB, 3        ; activates pull up resistor in PB3
loop:		                    ; label for main loop
                                ; labels must start with a letter and end with a colon
          CPI   PINA,0          ; compares the value of PINA (button) with 0
          BRNE  release         ; the result was different from 0 so the button is
                                ; released.Go to subroutine release
          SBI   PORTA,7         ; the result was 0 so the button is pressed. Turn
                                ; pin PA7 to HIGH (5V)
          JMP   done            ; avoids subroutine release
release:
          CBI   PORTA,7         ; Turns pin PA7 to LOW (0V)
done:                           ; land here after turn PA7 HIGH
          RJMP  loop            ; relative jump to label called loop
```

## The Stack

LIFO Last In First Out

`PUSH reg,value` copies a byte of data from to the first empty byte at the top of the Stack

`POP reg` removes a byte of data from the top of the stack to the specified register

## Macros

A macro is a group of instructions that you code once and are able to use as many times as necessary. The main difference between a macro and a subroutine is that the macro is expanded at the place where it is used, meaning it uses program memory for each of the instances. A macro can take up to 10 parameters referred to as @0-@9 and given as a coma delimited list.

```asm
.MACRO    DELAY                 ; This directive creates a macro called delay

.ENDMACRO                       ; Directive that ends the macro

DELAY
```

## Inline Assembly in C

It is possible to write Assembly code within a C program by using the following syntax in C:

```C
asm ("
// here your assembly code
    ")
```

## LED blink delay example

This is a sample of how an assembly program looks like.

```asm
; ledblink.asm
;
; Fab Academy
; February 2016
; by Francisco Sanchez
; CC-BY-SA 4.0 License
;
; This program blinks the LED of a helloworld board

.device attiny44 	 ; defines which device to assemble for
.org 0		        ; sets the programs origin

sbi DDRA, 7
; sbi(reg,bit): Sets a bit of a register.
; DDRA is the data direction register A
; Setting DDRA bit 7 makes pin PA7 a (digital) output
; A digital output can be switched ON/OFF for 5V or 0V

loop:
; label for main loop
; labels must start with a letter and end with a colon

sbi PORTA,7
; Sets bit 7 of register PORTA
; Turns pin PA7 to 5V

; Here it would come delay code

cbi PORTA,7
; Clears bit 7 of register PORTA
; Turns pin PA7 to 0V

; Here it would come delay code

rjmp loop
; relative jump to label called loop
```

## Programming Structures in Assembly

### Translate an If-then-else statement to AVR assembly code

<iframe width="853" height="480" src="https://www.youtube-nocookie.com/embed/xEJtdMQMcrs?showinfo=0" frameborder="0" allowfullscreen></iframe>

### Translate a for statement to AVR assembly code

<iframe width="853" height="480" src="https://www.youtube-nocookie.com/embed/i72IqHVlYoo?showinfo=0" frameborder="0" allowfullscreen></iframe>

### Translate a switch statement to AVR assembly code

<iframe width="960" height="720" src="https://www.youtube-nocookie.com/embed/_4S3w4CBZcI?rel=0&amp;showinfo=0" frameborder="0" allowfullscreen></iframe>

### Translate a while statement to AVR assembly code

<iframe width="853" height="480" src="https://www.youtube-nocookie.com/embed/HIPnr8V6foY?showinfo=0" frameborder="0" allowfullscreen></iframe>

---
[Back to Summary](../summary.md)
