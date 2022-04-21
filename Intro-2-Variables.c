#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP410.h"         // Include UBMP4.1 constant and function definitions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Program constant definitions
const unsigned char maxCount = 50;

// Program variable definitions
unsigned char SW2Count = 0;
bool SW2Pressed = false;
unsigned char SW5Count = 0;
bool SW5Pressed = false;
bool pressed = 0;
bool notPressed = 1;


int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
	{
        // Count SW2 button presses
        if(SW2 == pressed && SW2Pressed == false)
        {
            LED3 = 1;
            if(SW2Count < maxCount)
            {
                SW2Count = SW2Count + 1;
            }
            SW2Pressed = true;
        }


        if(SW5 == pressed && SW5Pressed == false)
        {
            LED6 = 1;
            if(SW5Count < maxCount)
            {
                SW5Count = SW5Count + 1;
            }
            SW5Pressed = true;
        }

        if(SW2Count == maxCount)
        {
            
            SW5Count = 0;
            LED4 = 1;
            LED3 = 1;
            __delay_ms(100);
            LED4 = 0;
            LED3 = 0;
            __delay_ms(100);
            LED4 = 1;
            LED3 = 1;
            __delay_ms(100);
	        LED4 = 0;
            LED3 = 0;
            __delay_ms(100);
        }
            

        if(SW5Count == maxCount)
        {
            SW2Count = 0;
            LED5 = 1;
            LED6 = 1;
            __delay_ms(100);
            LED5 = 0;
            LED6 = 0;
            __delay_ms(100);
            LED5 = 1;
            LED6 = 1;
            __delay_ms(100);
            LED5 = 0;
            LED6 = 0;
            __delay_ms(100);
            
        }

        // Clear 
        if(SW2 == notPressed)
        {
            LED3 = 0;
            SW2Pressed = false;
        }
       
        if(SW5 == notPressed)
        {
            LED6 = 0;
            SW5Pressed = false;
        }
        
        // Reset count and turn off LED D4 & D5
        if(SW3 == 0)
        {
            LED4 = 0;
            LED5 = 0;
 	        LED3 = 0;
	        LED6 = 0;
            SW2Count = 0;
            SW5Count = 0;
        }
        
        // Add a short delay to the main while loop.
        __delay_ms(10);
        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
    
}
SW5Count = 0;
     LED4 = 1;
         LED3 = 1;
          __delay_ms(100);
      LED4 = 0;
           LED3 = 0;
          __delay_ms(100);
         LED4 = 1;
         LED3 = 1;
            __delay_ms(100);
	      LED4 = 0;
           LED3 = 0;
          __delay_ms(100);
//
//
//
//
//