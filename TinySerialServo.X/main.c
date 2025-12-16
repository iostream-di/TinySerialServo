/*
 * File:   main.c
 * Author: dee
 *
 * Created on December 15, 2025, 7:34 PM
 */


#include <xc.h>
#include "config.h"
#include "sysled.h"

void main(void) {
    
    OSCCONbits.IRCF = 0b1110;
    OSCCONbits.SCS = 0b10;
    OSCCONbits.SPLLEN = 1u;
    while(!OSCSTATbits.HFIOFS);
    ANSELA = 0x00u;
    
    sysled_init();
    while(1){
        sysled_blink();
    }
}
