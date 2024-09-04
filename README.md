# TinyFanController
This fan controller is meant to, in as small a package as possible, take a standard 4 pin computer fan and control it using an ATTiny microcontroller. 

## I/O
* Power: 7-35 VDC (Note 1)
* K type Thermocouple
* 4 pin computer fan
Note 1: The power only feeds an L7805. As such a 5V fan is needed. This is board specific, and future designs might use a L7805 as well to power the fan.

## Microcontroller
The initial design uses a ATTIny85 microcontroller to read the thermocouple and output a 25kHz PWM signal to the fan PWM pin.
