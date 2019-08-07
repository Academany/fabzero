# IOT project overview

This is one of the possible final projects to demonstrate the integration of various skills acquired during the training. 

This project uses an AVR micro-controller with a sensor to acquire some sort of input and send it to the cloud via WiFi using an ESP-01. 

The ESP module itself is a more capable micro-controller, but the purpose of this assignment is to learn new techniques and integration, and this may sometimes require to make a circuit that is not the most cost-effective.

## Tasks

- ESP Firmware update
- Test ESP with AT-Commands
- Test micro-controller and sensor (send sensor value via serial to PC)
- Create thingsspeak account, and a channel
- Try sending data to the cloud using AT commands via serial monitor.
- Package everything.

### Firmware in ESP-01
It is possible that you are not using the latest Firmware or even some other firmware (written for another application) in the ESP-01. So, it's better to check and install the latest AT-command firmware. 

>In Linux you can use [esptool.py](https://github.com/espressif/esptool) to read/write the flash-memory in ESP.

> Instructions are available [here](https://robertoostenveld.nl/esp8266-at-firmware/), and in the source file found [here.](https://github.com/espressif/ESP8266_NONOS_SDK/releases/tag/v2.2.1)  

### Working with AT commands 

The ESP-01 is being used as a modem and the communication with the modem is done via a specific set commands, called AT commands.

>[Espressif Documentation for the AT commands.](https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf) 

### Power save 

There a two aspects to power saving
- Power saving in ESP module: by putting the module in deep-sleep mode or light-sleep mode.
> [Espressif Documentation on power saving](https://www.espressif.com/sites/default/files/9b-esp8266-low_power_solutions_en_0.pdf)
- Power saving in the AVR micro-controller.
  - Deactivating unnecessary hardware components when not in use.
  - Putting the uC in sleep mode
  - Automatic wake up after a specified time. 

> [Microchip article on power saving](https://microchipdeveloper.com/8avr:avrsleep)

> Another interesting  [article](https://www.garlicsoftware.com/articles/files/0662584a661f5b1cdb84dc2c17935537-1.php)

> **task:** compare the power consumption in different modes of operation