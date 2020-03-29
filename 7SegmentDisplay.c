/*
 * 7SegmentDisplay.c
 *
 *  Created on: Mar 28, 2020
 *      Author: igorazevedo
 */

#include <msp430.h>
#include <stdint.h>
#include "7SegmentDisplay.h"
#include "4DTouchSensor.h"

void configPins(){
    /* Configuration */

    // --- PINs ----

    //P2.5 --> out (a)
    P2DIR |= BIT5;
    P2OUT &= ~BIT5;

    //P2.4 --> out (b)
    P2DIR |= BIT4;
    P2OUT &= ~BIT4;

    //P3.7 --> out (c)
    P3DIR |= BIT7;
    P3OUT &= ~BIT7;

    //P6.4 --> out (d)
    P6DIR |= BIT4;
    P6OUT &= ~BIT4;

    //P6.3 --> out (e)
    P6DIR |= BIT3;
    P6OUT &= ~BIT3;

    //P6.2 --> out (f)
    P6DIR |= BIT2;
    P6OUT &= ~BIT2;

    //P6.1 --> out (g)
    P6DIR |= BIT1;
    P6OUT &= ~BIT1;

}

void turnOnNumber(uint8_t num){
    switch(num){
        case 1:
            turnOnOne();
            break;
        case 2:
            turnOnTwo();
            break;
        case 3:
            turnOnThree();
            break;
        case 4:
            turnOnFour();
            break;
        default:
            turnOnZero();
            break;
    }
}

void turnOnZero(){
    P2OUT |= BIT5;
    P2OUT |= BIT4;
    P3OUT |= BIT7;
    P6OUT |= BIT4;
    P6OUT |= BIT3;
    P6OUT |= BIT2;
    P6OUT &= ~BIT1;
}

void turnOnOne(){
    P2OUT &= ~BIT5;
    P2OUT |= BIT4;
    P3OUT |= BIT7;
    P6OUT &= ~BIT4;
    P6OUT &= ~BIT3;
    P6OUT &= ~BIT2;
    P6OUT &= ~BIT1;
}

void turnOnTwo(){
    P2OUT |= BIT5;
    P2OUT |= BIT4;
    P3OUT &= ~BIT7;
    P6OUT |= BIT4;
    P6OUT |= BIT3;
    P6OUT &= ~BIT2;
    P6OUT |= BIT1;
}

void turnOnThree(){
    P2OUT |= BIT5;
    P2OUT |= BIT4;
    P3OUT |= BIT7;
    P6OUT |= BIT4;
    P6OUT &= ~BIT3;
    P6OUT &= ~BIT2;
    P6OUT |= BIT1;
}

void turnOnFour(){
    P2OUT &= ~BIT5;
    P2OUT |= BIT4;
    P3OUT |= BIT7;
    P6OUT &= ~BIT4;
    P6OUT &= ~BIT3;
    P6OUT |= BIT2;
    P6OUT |= BIT1;
}


