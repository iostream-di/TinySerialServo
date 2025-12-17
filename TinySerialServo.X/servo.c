#include <xc.h>
#include <stdint.h>
#include "servo.h"

static volatile uint16_t setpoint = 1500;  // default center (µs)
static volatile uint16_t servo_pulse_us = 1500;  // default center (µs)




void __interrupt() isr(void) {
    static uint8_t phase = 0; // 0 = HIGH pulse, 1 = LOW remainder

    if (TMR1IF) {
        TMR1IF = 0;
        
        if (setpoint < servo_pulse_us){
            servo_pulse_us--;
        } else if (setpoint > servo_pulse_us){
            servo_pulse_us++;
        } 
        
        if (phase == 0) {
            // Start HIGH pulse on RA4
            LATAbits.LATA4 = 1;
            TMR1 = 65536u - servo_pulse_us;
            phase = 1;
        } else {
            LATAbits.LATA4 = 0;
            TMR1 = 65536u - (20000u - servo_pulse_us); // LOW remainder
            phase = 0;
        }
    }
}



void servo_init(void){
    // Digital output setup
    ANSELA = 0x00;         // all digital
    TRISA4 = 0;            // RA4 output
    LATAbits.LATA4 = 0;    // start low

    // Timer1 setup
    T1CONbits.TMR1CS = 0;     // Clock source = Fosc/4 (datasheet: TMR1CS=00)
    T1CONbits.T1CKPS = 0b110;  // Prescaler = 1:8 (datasheet: T1CKPS=11)
    TMR1H = 0;                // Clear Timer1 high byte
    TMR1L = 0;                // Clear Timer1 low byte
    PIR1bits.TMR1IF = 0;      // Clear interrupt flag (datasheet requirement)
    T1CONbits.TMR1ON = 1;     // Enable Timer1

    // Interrupts
    PIE1bits.TMR1IE = 1;      // Enable Timer1 interrupt
    INTCONbits.PEIE = 1;      // Enable peripheral interrupts
    INTCONbits.GIE = 1;       // Global interrupt enable


}

void servo_set_position_us(unsigned short us) {
    if (us < 1000) us = 1000;
    if (us > 2000) us = 2000;
    setpoint = us;
}

