




```makefile
file_name = main-int  // this is the name of the program

device  = attiny44  // this is the processor
F_CPU   = 1000000   // this is the clock frecuency

// targets start here

object:
	 avr-gcc -g -Os -mmcu=$(device) -c $(file_name).c

link:
	 avr-gcc -g -mmcu=$(device) -o $(file_name).elf $(file_name).o

hexfile:
	 avr-objcopy -j .text -j .data -O ihex $(file_name).elf $(file_name).hex


hex: object link hexfile

flash:  
	avrdude -c USBtiny -p t44 -U flash:w:$(file_name).hex
  ```
