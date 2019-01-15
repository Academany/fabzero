# Electronics Production

* [Preparing the machine](#preparing-the-machine)
* [Use proper materials and tools](#use-proper-materials-and-tools)
* [Preparing the job](#preparing-the-job)
* [Milling the board](#milling-the-board)
* [Stuffing the board](#stuffing-the-board)
  * [Picking the components](#picking-the-components)
  * [Soldering](#soldering)
  * [Undo. Using the heat gun](#undo-using-the-heat-gun)
* [Smoke test :boom:](#smoke-test-boom)
* [Programming the board](#programming-the-board)
  * [Obtaining the toolchain](#obtaining-the-toolchain)
  * [Compiling the code](#compiling-the-code)
  * [Uploading the code](#uploading-the-code)
* [It doesn't work: Debugging](#it-doesnt-work-debugging)

This is **one of the most important skills for a fabber**. From now on, you will be producing electronics continuously, for your assignments and final project. So **mastering this process is essential**. This is a fast process. You can mill a board in half an hour, stuff it in less than one hour and upload a program to it in a matter of minutes.

## Preparing the machine

Half of fab academy assignments involve using this machine (or the SRM-20). [Adam Harris](http://fabacademy.org/archives/2014/students/harris.adam/index.html), a 2014 student made an amazing tutorial about using the Roland Modela MDX-20 (mostly valid the SRM-20)

<iframe width="853" height="480" src="https://www.youtube-nocookie.com/embed/jkLJI8L7TUs?rel=0&amp;showinfo=0" frameborder="0" allowfullscreen></iframe>

## Use proper materials and tools

Make sure that you have at least the critical materials. At the very minimum you should have:

* FR1 boards.
* 1/64 and 1/32 flat end milling bits from Carbide Depot

I recommend that you get them from Fab Foundation or another Lab. Over years I have been looking for a local replacement with no success, the quality is very poor. But do try to compare local sources if you have the chance.

Some people use FR4 boards and V-shape milling bits.

## Preparing the job

Milling circuit boards is a process **very sensitive to height differences**. Even a tiny bubble in the double sided tape, remains of old glue will affect the milling. Take your time to carefully prepare the board for milling.

**Always** use a sacrificial material. I recommend another PCB board with the paper side looking up. I do not recommend acrylic or wood since the height is not consistent across the surface.

Be careful with the 1/64 milling bit. It breaks easily.

## Milling the board

## Stuffing the board

### Picking the components

### Soldering

* It’s not like painting. Doesn’t work like this. Soldering Iron in, Solder in, Solder out, Soldering Iron out.
* Use the double side tape to fix the board to the table
* Start with the microcontroller, continue towards the perimeter
* Easy with the tweezers
* Soldering day - No coffee
* Use good lighting and loupes

### Undo. Using the heat gun

Proper use of the heat gun. Remember to put it in cold air after use until no heat comes out.

## Smoke test :boom:

The moment of truth arrrives when you feel confident enough to power the board :sweat:. As usual in all critical events of life, you have two options:

1. You could take a leap of faith and power the board straight away. This is the equivalent of clicking the [I'm feeling lucky](https://www.google.com/) button
2. There are many things that could go wronh. But you could at least check with a multimeter that VCC and GND are not shorted

If after a few seconds of powering the board there is no significant heat, smoke, fire or explosion, go to the next step.

> **Warning!** Always wear safety glasses before first powering a board *that you made*. Just in case

## Programming the board

The final step is loading the program to the microcontroller. 

### Obtaining the toolchain

### Compiling the code

Download this [sample code](files/code101/samplecode.zip) and test if you can compile it. Unzip the code somewhere in your computer and you will see a `.c` file and and `Makefile`. The `.c` file is the (souce) code. It is an editable text file. The microcontroller does not understand this. We have to **compile** it. In a terminal type:

```bash
make program
```

### Uploading the code

You should obtain a `.hex` file. This is a hexadecimal file with the actual instructions. We now can upload it to the microcontroller via the FabISP

```bash
make flash
```

> **Think about it.** Did you know that there is a finite amount of times you can program a microcontroller? Find out how many by looking at the [datasheet](files/datasheets/attiny44.pdf).

If everything went well, as soon as the upload finishes, the code will start running in the microcontroller. If you want to learn more about programming and what these *make* commands do, please proceed to the [coding chapters](code101.md).

## It doesn't work: Debugging

Finding errors in the programming step is normal. A common fail is that when there is an error the student just mills another board, and another, and another... until he succeeds. This is wrong. You have to learn how to debug your boards. You have to find and isolate where is the error. The most important thing when debugging is **reading** what is the error you are receiving, it will give you hints on how to proceed. Here you are some (not all!) things you can try:

* It can be the USB port. Try different USB ports. Problems have been reported in some USB3 ports. Try a USB hub or a USB2 port.
* It can be the USB cable. Try a different one.
* It can be something related to your computer. Try another computer.

If all of this does not work then probably there is something wrong in the ISP cable or the fabISP itself:

* Check the ISP ribbon cable polarity. Are you connecting it in the right way?
* If you fabricated the ISP ribbon cable and IDC connector inspect the terminal with a microscope. Make sure no wires are touching each other.
* Check the board in a microscope. Check all the solderings. Look for cold soldering. Check for shorts. Check for bad soldering.

There is no magic in debugging. **No one on Earth will be able to tell you what happens with your board**. This is just a systematic process. Just try everything and make a debugging table so I or anyone can help you with that.

Good luck and happy electronics production!

---
[Back to Summary](../summary.md)
