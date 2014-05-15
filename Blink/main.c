#include  <msp430fr5739.h>

unsigned int i = 0;

void main(void) {
    //Stop watchdog timer.
    WDTCTL = WDTPW + WDTHOLD;
    // LED J.0 J.1 J.2 J.3 3.4 3.5. 3.6 3.7
    // enable PJ.0 and PJ.1 as outputs
    PJDIR |= 0x01 | 0x02 | 0x04 | 0x08;
    P3DIR |= 0x10 | 0x20 | 0x40 | 0x80;
    
    // switch on first LED and switch off second LED
    //PJOUT = (PJOUT & ~(0x01 | 0x02)) | 0x01;
    PJOUT = 0xFF;
    P3OUT = 0xFF; //0x08 | 0x10 | 0x20 | 0x40;
    
    // main loop
    for (;;) {
        // toggle LEDs
        PJOUT ^= 0x01 | 0x02 | 0x04 | 0x08;
        P3DIR ^= 0x10 | 0x20 | 0x40 | 0x80;
        // delay
        for(i=0; i< 20000; i++);
    }
}
