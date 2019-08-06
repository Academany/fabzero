# Pulse width modulation PWM

---

* [What?](#what)
* [Why?](#why)
* [How?](#How)
* [Where?](#Where)


## What?

 As the name implies, we use PWM feature to generate pulses with custom width. But this is different from normal square wave, where we can control the frequency to change the pulse width, but in that case the width/duration of both high and low stages change equally.

 In pulse width modulation, we usually change the duration of high stage and leave the frequency unchanged.

 Sometimes we specify the PWM signal with it's frequency and duty-cycle, which is the percentage of time the signal stays high, compared to the overall cycle duration.

## Why?

 Most common application for PWM are in power control.

 We can control the energy output of a device in three different ways. As we know energy output is **power x time**, and power is **voltage x current**, so, we can control voltage, current or time. In PWM we control the time, we control the time for which we deliver the power. So we keep the device on, at full power for a while and then turn it off. We repeat the process so fast at short intervals so that the user perceives a reduced averaged output power.

 In many cases we use capacitors or inductors etc. to make the output appear smooth, by storing the energy when the power supply is on and releasing it when it's off.

 Another use case is in signaling. Common example is servo motor. In which a PWM signal with 50Hz is used, and a duty cycle between 5-10% is used to specify the angle of rotation. (cycle duration is 20ms and the pulse duration id between 1ms(5%) and 2ms(10%))

## How?

Generating the PWM can be done the hard way by turning a pin HIGH and LOW at the required time. But nobody really does it this way, because it's very inefficient. There are hardware PWM generators, We can also do this with the help of timer-interrupts.

For detailed information you must read the datasheet, especially the **8-bit Timer/Counter0 with PWM** and **16-bit Timer/Counter1 with PWM** sections of [Tiny44 Dataheet](http://ww1.microchip.com/downloads/en/devicedoc/Atmel-7701_Automotive-Microcontrollers-ATtiny24-44-84_Datasheet.pdf).
And the [application note](http://ww1.microchip.com/downloads/en/AppNotes/Atmel-2542-Using-the-AVR-High-speed-PWM_ApplicationNote_AVR131.pdf)

Whether you do it manually or in hardware, the basic idea is very simple.

* The counter starts at zero and counts up at the rate defined by prescaler. At this point the output is also set (set HIGH) or cleared(set LOW), for simplicity let's assume that we are setting at zero.

* When the counter reaches a predefined value, the output is cleared.

* The counter reaches the maximum value, overflows and resets to zero or it reaches a predefined top value and resets to zero.

**In short** the Fast PWM operates likes

* Counter starts at BOTTOM and starts counting up. Also sets( or clears for inverted mode) the output.
* Clears (or sets) output on compare match.
* Counter reaches TOP and resets to BOTTOM, and repeat.

This is the general working, then there are special modes like **phase corrected PWM** which operates in a slightly different manner.

In Phase corrected PWMs
* Counter starts at BOTTOM and counts up.
* Sets (or clears) output on compare match.
* Counter reaches TOP and starts counting down.
* Clears (or Sets) output on compare match.
* Counter reaches BOTTOM and starts counting up again, and repeat.

Either way, Fast or Phase corrected, once configured these generating these PWM signals doesn't require any CPU intervention and our CPU is free for doing other tasks. We need CPU only if we need to update certain registers to change the PWM frequency or Duty cycle.

Now, as you know, **Timer1** is a bit special, so is the PWM from Timer1. It can operate in many different ways. Unlike other 8-bit timer based PWMs, this one can change PWM base frequency along with the duty cycle. This is achieved by configuring the counter to reset at **ICR1**.

#### Manually generating PWM

There could be multiple scenarios where we may have to skip using hardware PWM. Perhaps our design doesn't allow PWM pins to be used. Or we may need better control over Timer0 based PWM.

One example would be,
Setting **Timer0** in **CTC** mode, where it counts from **0** (BOTTOM) to **OCR0A** (TOP) and resets. This, along with the prescaler settings defines the base frequency for the PWM, and we can change it by changing **OCR0A**.
Now, we have a few options,
1.
  * Enable **OCIE0A**: Timer/Counter0 Output Compare Match A Interrupt.
  * In the Compare Match A Interrupt Vector sub-routine, we toggle the output pin. We could toggle any output pin we choose.

  * We need to reset the output pin to complete the cycle, this could be done with the help of **OCIE0B**: Timer/Counter0 Output Compare Match B Interrupt. The value should be between the **BOTTOM** and **TOP**, the interrupt sub-subroutine is almost the same as the other, toggle the selected output pin.

  There are couple of advantages and disadvantages for this method. On the plus side, we have frequency and duty cycle control over any PWM channels, also we can use any output pin for generating the PWM.

  On the contrary, this procedure consumes some CPU cycles, even for normal operation, which may affect other operations.

## Where?

 Some use cases:

 * Breathing LED effect in notification LEDs.
 * Dimming Light.
 * LCD backlight.
 * Fan speed control.
 * DC-DC controllers.
 * Power regulators.
 * Motor speed controllers.
 * ...

---
[Back to Summary](../summary.md)
