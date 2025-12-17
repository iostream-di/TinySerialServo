/* 
 * File:   config.h
 * Author: dee
 *
 * Created on December 15, 2025, 7:58 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = ON
#pragma config CLKOUTEN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
    
#pragma config WRT = OFF
#pragma config PLLEN = ON
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LVP = OFF
    
#define _XTAL_FREQ 32000000


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

