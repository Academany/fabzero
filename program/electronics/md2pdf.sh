#!/bin/bash

pandoc \
    -s \
    --include-in-header pdf-style.tex \
    -V geometry:a4paper \
    -V geometry:lmargin=2.5cm \
    -V geometry:rmargin=3.5cm \
    -V geometry:tmargin=3.5cm \
    -V geometry:bmargin=2.5cm \
    -V fontsize=12pt \
    --columns=40 \
    code101.md interrupts.md timerinterrupt.md timercounter.md adc.md assembly.md \
    -f gfm \
    -o tot-stessa.pdf 
