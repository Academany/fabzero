# Timer/counters in the attiny44
The timer/counter is a piece of hardware inside the microcontroller that can be used to count and control time. Actually, it does not count time, because it doesn't know anything about time. It should be actually named counter because it just counts clock cycles. What makes timers so interesting is the fact that they are totally independent of the CPU. The timers run parallel to the CPU without its intervention.

> Note: All the information listed here is a extract from the attiny44 datasheet. It just organized differently in order to be easier to understand. Other microcontrollers will have different register names.

## The problem of the blinking LED
Let's see the classical blinking LED code, where we have an LED in PA3, connected to ground.
```
#include <avr/io.h>
#include <util/delay.h>

int main (void) {
    DDRA |= (1 << PA3); // set LED pin as output

while(1) {           
      PORTA |= (1 << PA3);  // turn on the LED
      _delay_ms(1000);      // wait a second
      PORTA &= ~(1 << PA3); // turn off the LED
      _delay_ms(1000);      // wait a second
         }
  }
  ```
The problem when counting time this way, is that the microcontroller cannot do anything else while we are waiting with the delay. As your coding abilities increase you will notice a limitation in what you can achieve due to this problem. In fact, you should NEVER use delays.

## The timers/counters
The ATtiny44 has two independent internal timers. One 8-bit (TIMER0) and another 16-bit (TIMER1), each with 2 PWM channels (more on this later). **Timers are actually registers** that increase from zero to 255, for the 8-bit:

![](/img/timercounter/tcnt0.png)

Or from 0 to 65535, for the 16-bit register TCNT1, which is splitted in two 8-bit registers, high and low:

![](/img/timercounter/tcnt1.png)

When they reach the maximum value, they overflow back to zero and start counting again. So far, so good.

## Operation modes
Timers have different modes of operation. We will focus in two for now: Normal mode (counter), and CTC mode. One at a time.

### Normal mode
By default the timers will run in normal mode. They will count from 0 to their maximum value 255/65535, and then overflow. The problem with this mode is that it is uncommon that we want to count up to that specific number, that is why the have the next mode.

### CTC mode
This is *clear timer on compare match* mode. This is the most common case. We will load a specific value in a register and then we will count up to that number. In each timer you can set up to 2 independent values that will trigger 2 independent interrupts. These for TIMER0:

![](/img/timercounter/ocr0a.png)
![](/img/timercounter/ocr0b.png)

And these for TIMER1:

![](/img/timercounter/ocr1ab.png)

### Selecting the mode of Operation
Operation modes are set with the control registers TCCR0A and TCCR0B for the 8-bit TIMER0, according to the following table.

![](/img/timercounter/tccr0a.png)
![](/img/timercounter/tccr0b.png)
![](/img/timercounter/timer0-wgm.png)

And TCCR1A and TCCR1B for the 16-bit TIMER1.

![](/img/timercounter/tccr1a.png)
![](/img/timercounter/tccr1b.png)
![](/img/timercounter/timer1-wgm.png)

## Timer Interrupts
Timers generate interrupts which is how they can interact with your program. As we saw before, an interrupt is an event that occurs when a particular trigger (either from an internal or external source) happens. The interrupt allows the program to stop what it was doing, perform a short task, and then return to where it left off in the main program. To enable timer interrupts, first we have to include the interrupt library and enable global interrupts

`sei();`

Then we have to mask which interrupt we want to trigger. For TIMER0 we have:

![](/img/timercounter/timsk0.png)

* Setting **TOIE0** bit will enable the interrupt in normal mode of operation
* Setting **OCIE0A** bit will enable the interrupt in CTC mode of operation when **TCNT0=OCR0A**
* Setting **OCIE0B** bit will enable the interrupt in CTC mode of operation when **TCNT0=OCR0B**

And these are the corresponding vectors:

![](/img/interrupts/vectors.png)

## The Prescaler
By default the timer registers increment at the speed of the microcontroller (if a clock speed of 20 MHz is used, then 20,000,000 times per second). But usually that's too fast, so it can be slowed down by dividing the speed by a certain amount. This is called prescaling. The prescaler can be set to 8, 64, 256 or 1024 compared to the system clock. The prescaler is set using the control registers TCCR0B and TCCR1B.

![](/img/timercounter/tccr0b.png)
![](/img/timercounter/timer0-prescaler.png)

![](/img/timercounter/tccr1b.png)
![](/img/timercounter/timer1-prescaler.png)

> WARNING! Once you set the prescaler, the counter will start!

## Example: Set 1 second timer
In this example we are going to consider all the above to set up a 1 second timer on an attiny44 microcontroller with an external 20MHz clock source using TIMER1 (the 16-bit timer).

At 20Mhz, a clock cycle is 50ns. Counting to 65535 at this speed with take exactly 3.277ms. So we will have to trigger the timer with a prescaler value (by setting the Clock Select bits CS12:10) in Timer/Counter1 Control Register B (TCCR1B). This allows us to slow down the timer by a factor of 1, 8, 64, 256 or 1024 compared with the clock source. However, it is unlikely that counting to 65535 at any of these speeds with take exactly one second as we see in the table below:

Pre-scaler value | Time
--- | ---
1 | 3.277 ms
8 | 26.216 ms
64 | 209.728 ms
256 | 838.912 ms
1024 | 3.355392 s

We see that we will have to set the pre-scaler to 1024 in order to be able to count at least a second.

Now need to calculate what number must be counted to with this pre-scaler value, and make the timer overflow when it hits that number. This is CTC (Clear Timer on Compare) mode. To use this mode, the Waveform Generation Mode bits (WGM13:10) in TCCR1A and TCCR1B must be set accordingly.

`TCCR1B |= (1 << WGM12); // configure timer1 for CTC mode`

To ensure that a signal is received when the timer overflows, the Timer/Counter1 Output Compare A Match interrupt (OCIE1A) bit must be set in the Timer/Counter1 Interrupt Mask Register (TIMSK1) and global interrupts have to be enabled.

```
TIMSK1 |= (1 << OCIE1A); // enable the CTC interrupt
sei();
```
So what number shall we count to? As you see in the table above, counting to 65535 at this speed would take 3.355392 seconds. Therefore 1 second will take 65535/3.355392=19531.25 increments. To set this as the maximum the timer should count to, we set Output Compare Register 1 A (OCR1A) to 19531.

`OCR1A   = 19531; // set the CTC compare value`

That was everything required to prepare the timer, so the only thing remaining is triggering it:

`TCCR1B |= ((1 << CS10) | (1 << CS12)); // start the timer   at 20MHz/1024`

Finally we have to set the ISR. In this case setting the OCIE1A bit corresponds to the TIM1_COMPA_vect Interrupt Service Routine.
```
ISR(TIM1_COMPA_vect) {
  // here the routine
}
```
Inside this routine, we can toggle the LED as before.
