/*
 * MSP430 PWM I
 * AUTOR: LUIZ FERNANDO PALARMINI
 * EXEMPLO DE PWM: CONFIGURANDO O DUTY CYCLE
 */

#include <msp430.h> 


int main(void) {

    //##########################################//
    //####  CONFIGURA��O DO WATCHDOG TIMER  ####//
    //##########################################//

    WDTCTL = WDTPW | WDTHOLD;       //WATCHDOG TIMER PARADO

    //##########################################//
    //#######  CONFIGURA��O DO CLOCK  ##########//
    //##########################################//

    DCOCTL = 0;                     //
    BCSCTL1 = CALBC1_1MHZ;          //CONFIGURA CLOCK EM 1 MHZ
    DCOCTL = CALDCO_1MHZ;           //

    //##########################################//
    //##########  DECLARA��O DE I/Os  ##########//
    //##########################################//

    P1DIR |= 0x40;          //P1.6 IMPLEMENTADO COMO SA�DA
    P1SEL |= 0x40;          //CONFIGURANDO P1.6 COMO PERIF�RICO TA0.1

    //##########################################//
    //#######  CONFIGURA��O DO TIMER0_A  #######//
    //##########################################//

    TACCR0 = 1000;          //PER�ODO DO PWM
    TACCTL1 = OUTMOD_7;     //MODO DE SA�DA DO TIMER0_A: RESET/SET
    TACCR1 = 100;           //DUTY CYCLE DO PWM EM 10%
    TACTL = TASSEL_2 + MC_1;    //TASSEL_2 -> CLOCK SOURCE: MCLK    MC_1 ->                                     //TIMER COM CONTAGEM PROGRESSIVA DE 0 AT� TACCR1

    _BIS_SR(CPUOFF);        //DESLIGA A CPU PARA ECONOMIZAR CONSUMO (LPM0)

    return 0;

}
