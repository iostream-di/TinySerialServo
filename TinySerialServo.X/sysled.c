#include "sysled.h"
#include "config.h"

static unsigned char sysled_state;
static unsigned char sysled_isEnabled;
static unsigned char sysled_activeDrive;

static void drive(void){
    if (sysled_isEnabled)
        pinWrite(PIN_SYSLED, (__bit)sysled_state);
}

void sysled_init(void){
    pinMode(A0, OUTPUT);
    pinWrite(PIN_SYSLED, LOW);
    sysled_isEnabled = 1u;
    sysled_activeDrive = 1u;
}

void sysled_set_drive(unsigned char mode){
    sysled_activeDrive = mode;
}

void sysled_enable(void){
    sysled_isEnabled = 1u;
}

void sysled_disable(void){
    sysled_isEnabled = 0u;
}

void sysled_on(void){
    sysled_state = (__bit)sysled_activeDrive;
    drive();
}

void sysled_off(void){
    sysled_state = (__bit)!sysled_activeDrive;
    drive();
}

void sysled_blink(void){
    sysled_state = ~sysled_state;
    drive();
    __delay_ms(50);
    sysled_state = ~sysled_state;
    drive();
    __delay_ms(50);
}

void sysled_toggle(void){
    sysled_state = ~sysled_state;
    drive();
}

void sysled_drive(unsigned char state){
    sysled_state = state;
    drive();
}

