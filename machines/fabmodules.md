# Compiled (legacy) Fab Modules

* [Installation](#installation)
* [Adding printers in CUPS](#adding-printers-in-cups)
* [Running the compiled version](#running-the-compiled-version)

## Installation

Installation is not difficult, just follow the instructions found in the [kokompe project page](http://kokompe.cba.mit.edu/), install the prerequisites:

 Thet download this modified `.zip` file, that solves a problem with newer giflib version, uncompress it and do:

```bash
make clean
make fab
sudo make install # recommended and needed for kokopelli retro
```

**Note for new Linux distributions:** Compiled fab modules development has been abandoned. I (Francisco) keep a modified version that works fine with Manjaro linux. If you need help send me a note. Download the source from [here](./files/fab_src.zip)

## Adding printers in CUPS

Make sure you belong to `lp` and `sys` groups before adding a printer in CUPS. For checking which groups you belong to, type `groups username` in a terminal window. Kindly replace `username` with your actual username before sending me an email. Then to add a user to a group use this syntax `sudo usermod -a -G groupname username`.

Type `localhost:631` in a web browser. You will be prompted for your user password.

## Running the compiled version

Just type `fab` in a terminal window.
