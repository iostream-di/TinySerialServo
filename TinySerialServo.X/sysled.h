/* 
 * File:   sysled.h
 * Author: dee
 *
 * Created on December 15, 2025, 7:37 PM
 */

#ifndef SYSLED_H
#define	SYSLED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#include "pins.h"
    


    

    extern void sysled_init(void);
    extern void sysled_set_drive(unsigned char mode);
    extern void sysled_enable(void);
    extern void sysled_disable(void);
    extern void sysled_on(void);
    extern void sysled_off(void);
    extern void sysled_blink(void);
    extern void sysled_toggle(void);
    extern void sysled_drive(unsigned char state);

#ifdef	__cplusplus
}
#endif

#endif	/* SYSLED_H */

