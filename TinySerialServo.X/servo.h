/* 
 * File:   servo.h
 * Author: David Martinez
 *
 * Created on December 16, 2025, 8:46 AM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif

    extern void servo_init(void);
    extern void servo_set_position_us(unsigned short us);

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

