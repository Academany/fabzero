# IOT Final Project

The goal of this project is integrating the skills acquired in the previous sessions to produce an IOT device that sends data to the Internet. The skills to develop include design and fabrication of a doubled sided circuit board, programming making use of low power techniques. It will also cover the design and fabrication of the enclosure. The deadline is Friday EOD. Let's get started.

## ThingSpeak Account

We will use ThingSpeak.com for storing and visualizing our data. There are other several platforms like thethings.io, thinger.io, etc.

- Create an ThingSpeak.com account
- Create a new channel with one field for storing the input device data
- Give public access to the channel (example: https://thingspeak.com/channels/842041)
- Use the API keys in your code to write data to ThingSpeak 

## Circuit board

Using Eagle or KiCAD design a double sided circuit board and generate the production images.

The main components of the board are:

- ESP-01 Wifi Module
- Atmega 328 microcontroller
- LED
- Push button
- 3.3 V Regulator
- Input device (RTD 1K Temperature Sensor)

> **Hint:** Download the Fab library from the [Fab Academy page](http://academy.cba.mit.edu/classes/electronics_design/index.html)

Fabricate your board using one of the milling machines (top layer traces, drills and outline cut, and bottom layer traces). Use https://fabfoundation.github.io/mods/ to generate the toolpaths and operate the machines.

Program the board and send the data using MQTT (or alternatively ThingSpeak) library and AT/T commands. 

## Enclosure

Design and fabricate an enclosure using any (as many as possible) technique available in a Fab Lab. Think about the following aspects before start the design process:

- Maintenance
- Ventilation
- Dust / humidity
- Durability
- Integration with the environment
- ...

## Time management

Develop your time management skills with a table of due tasks and time allocation for each one.

## Project Management

- Organize and sort your tasks
- Set priorities
- Divide tasks to the team members
- Throw as many as parallel tasks as you can
- Deliver



