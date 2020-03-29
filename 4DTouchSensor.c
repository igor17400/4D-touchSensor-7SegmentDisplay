/*
 * 4DTouchSensor.c
 *
 *  Created on: Mar 28, 2020
 *      Author: igorazevedo
 */

#include <msp430.h>
#include <stdint.h>
#include "4DTouchSensor.h"

void configPins4D(){
    /* Configuration */

    // --- PINs ----

    //P4.5 --> in (1)
    P4DIR &= ~BIT5;
    P4REN |= BIT5;
    P4OUT &= ~BIT5;

    //P5.2 --> in (2)
    P5DIR &= ~BIT2;
    P5REN |= BIT2;
    P5OUT &= ~BIT2;

    //P5.4 --> in (3)
    P5DIR &= ~BIT4;
    P5REN |= BIT4;
    P5OUT &= ~BIT4;

    //P5.0 --> in (4)
    P5DIR &= ~BIT0;
    P5REN |= BIT0;
    P5OUT &= ~BIT0;

}

