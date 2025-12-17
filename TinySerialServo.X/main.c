/*
 * File:   main.c
 * Author: dee
 *
 * Created on December 15, 2025, 7:34 PM
 */


#include <xc.h>
#include "config.h"
#include "sysled.h"
#include "button.h"
#include "servo.h"

static volatile unsigned long tick = 0;
static unsigned char dir = 0;

void main(void) {
    
    // HFINTOSC at 8 MHz, enable PLL for 32 MHz
    OSCCONbits.IRCF   = 0b111;  // 8 MHz HFINTOSC
    OSCCONbits.SCS    = 0b10;   // Clock source = internal
    OSCCONbits.SPLLEN = 1;      // Enable PLL (×4) -> 32 MHz
    ANSELA = 0x00u;
    
    sysled_init();
    button_init();
    servo_init();
    //servo_set_position_us(1500);
    //__delay_ms(5000);
    
    while(1){
        sysled_drive(button_read());
        if (tick < 3){
            tick++;
        } else {
            if (dir){
                servo_set_position_us(1000);
            } else {
                servo_set_position_us(2000);
            }
            dir = !dir;
            tick = 0;
        }
    }
}
