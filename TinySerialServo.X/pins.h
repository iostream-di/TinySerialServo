/* 
 * File:   pins.h
 * Author: David Martinez
 *
 * Created on December 16, 2025, 8:17 AM
 */

#ifndef PINS_H
#define	PINS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
#ifndef HIGH
#define HIGH 1u
#endif
#ifndef LOW
#define LOW 0u
#endif
#ifndef OUTPUT
#define OUTPUT 0u
#endif
#ifndef INPUT
#define INPUT 1u
#endif
    
#define A0 0u
#define A1 1u
#define A2 2u
#define A3 3u
#define A4 4u
#define A5 5u
    
#define PIN_SYSLED 0u
#define PIN_BUTTON 5u
#define PIN_PWM 4u
    
static inline void pinMode(unsigned char pin, unsigned char mode) {
    switch(pin) {
        case A0: TRISA0 = (__bit)mode; break;
        case A1: TRISA1 = (__bit)mode; break;
        case A2: TRISA2 = (__bit)mode; break;
        case A3: TRISA3 = (__bit)mode; break;
        case A4: TRISA4 = (__bit)mode; break;
        case A5: TRISA5 = (__bit)mode; break; // input only
    }
}

static inline void pinWrite(unsigned char pin, unsigned char value) {
    switch(pin) {
        case A0: LATAbits.LATA0 = (__bit)value; break;
        case A1: LATAbits.LATA1 = (__bit)value; break;
        case A2: LATAbits.LATA2 = (__bit)value; break;
        case A3: RA3 = (__bit)value; break;
        case A4: LATAbits.LATA4 = (__bit)value; break;
        //case A5: RA5 = value; break;
    }
}

static inline unsigned char pinRead(unsigned char pin) {
    switch(pin) {
        case A0: return RA0;
        case A1: return RA1;
        case A2: return RA2;
        case A3: return RA3;
        case A4: return RA4;
        case A5: return RA5;
    }
    return 0;
}

#ifdef	__cplusplus
}
#endif

#endif	/* PINS_H */

