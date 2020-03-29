#include <msp430.h> 
#include <stdint.h>
#include "7SegmentDisplay.h"
#include "4DTouchSensor.h"


/**
 * author: Igor Lima Rocha Azevedo
 * email: igorlima1740@gmail.com
 *
 * main.c
 */

void debounce(uint16_t dt){
    volatile uint16_t i = dt;
    while(i--);
    return;
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings
	
	//pins configuration
	configPins();
	configPins4D();

	while(1){
	    while(!(P4IN & BIT5) && !(P5IN & BIT2) && !(P5IN & BIT4) && !(P5IN & BIT0));
        if( (P4IN & BIT5) ){
            turnOnNumber(1);
        } else if( (P5IN & BIT2) ){
            turnOnNumber(2);
        } else if( (P5IN & BIT4) ){
            turnOnNumber(3);
        } else if( (P5IN & BIT0) ){
            turnOnNumber(4);
        } else {
            turnOnNumber(0);
        }
	}

	return 0;
}




