## Timer interrupts
One of the problems you will find when you program your microcontroller is the use of delays. When you use a delay, the microcontroller halts. It cannot do anything.

counter it counts clock cycles

is very fast

prescaler cs12 11 10 bits 110 motor
TCCR1B
TCCR1B

ctc mode clear timer on compare

set compare match OCR1A=19530

cli();
TCCR1A=0
TCCR1B=0  //normal OPERATIOn OC1A anb b disconnected


ISR(TIMER1_COMPA_vect)   // 16bit Timer
{

}

OC0A OC0B OC1A
