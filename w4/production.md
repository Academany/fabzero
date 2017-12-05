# Electronics Production

This is **one of the most important weeks in fab academy**. From now on, you will be producing electronics continuously, for your assignments and final project. So **mastering this process is essential**. This is a fast process. You can cut a board in half an hour, stuff it in say one hour and program it in another half an hour.

## Preparing the machine
Half of fab academy assignments involve using this machine (or the SRM-20). [Adam Harris](http://fabacademy.org/archives/2014/students/harris.adam/index.html), a 2014 student made an amazing tutorial about using the Roland Modela MDX-20 (mostly valid the SRM-20)

<iframe width="853" height="480" src="https://www.youtube-nocookie.com/embed/jkLJI8L7TUs?rel=0&amp;showinfo=0" frameborder="0" allowfullscreen></iframe>

## Use proper materials
Make sure that you have at least the critical materials.

* FR1 boards. Make sure they are not FR4
* 1/64 and 1/32 flat end milling bits from Carbide Depot

I recommend that you get them from Fab Foundation or another Lab. Over years I have been looking for a local replacement with no success, the quality is very poor. But do try to compare local sources if you have the chance.

Some people use FR4 boards and V-shape milling bits.

## Preparing the job
Some other things to take into account:

* Milling circuit boards is a process **very sensitive to height differences**. Even a tiny bubble in the double sided tape, remains of old glue will affect the milling. Take your time to carefully prepare the board for milling.
* **Always** use a sacrificial material. I recommend another PCB board with the paper side looking up. I do not recommend acrylic or wood since the height is not consistent across the surface.
* Be careful with the 1/64 milling bit. It breaks easily.

## Milling the board

## Stuffing the board

### Soldering

* It’s not like painting. Doesn’t work like this. Soldering Iron in, Solder in, Solder out, Soldering Iron out.
* Use the double side tape to fix the board to the table
* Start with the microcontroller, continue towards the perimeter
* Easy with the tweezers
* Soldering day - No coffee
* Use good lighting and loupes

### Using the heat gun
Proper use of the heat gun. Remember to put it in cold air after use until no heat comes out.

## Programming the board

## It doesn't work: Debugging
Finding errors in the programming step is normal. A common fail is that when there is an error the student just mills another board, and another, and another... until he succeeds. This is wrong. You have to learn how to debug your boards. You have to find and isolate where is the error. The most important thing when debugging is **reading** what is the error you are receiving, it will give you hints on how to proceed. Here you are some (not all!) things you can try:

* It can be the USB port. Try different USB ports. Problems have been reported in some USB3 ports. Try a USB hub or a USB2 port.
* It can be the USB cable. Try a different one.
* It can be something related to your computer. Try another computer.

If all of this does not work then probably there is something wrong in the ISP cable or the fabISP itself:

* Check the ISP ribbon cable polarity. Are you connecting it in the right way?
* If you fabricated the ISP ribbon cable and IDC connector inspect the terminal with a microscope. Make sure no wires are touching each other.
* Check the board in a microscope. Check all the solderings. Look for cold soldering. Check for shorts. Check for bad soldering.

> There is no magic in debugging. **No one on Earth will be able to tell you what happens with your board**. This is just a systematic process. Just try everything and make a debugging table so I or anyone can help you with that.

Good luck and happy electronics production!

---
[Back to Summary](../summary.md)
