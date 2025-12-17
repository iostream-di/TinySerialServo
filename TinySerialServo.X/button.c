#include <xc.h>
#include "button.h"

void button_init(void){
    TRISA5 = 1u;
}

unsigned char button_read(void){
    return !RA5;
}
