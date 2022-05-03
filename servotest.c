#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Program variable definitions
const unsigned char high = 1;
const unsigned char low = 0;

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    while(1)
	{
        //use first pin H1
        // 1ms 0 
        // 1.5ms 90
        // 2ms 180
        if(SW2 == 0){
            H1OUT = high;
            __delay_ms(1.5);
            H1OUT = low;
            LED4 = high;

        }
        else{
            LED4 = 0;
        }


        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}