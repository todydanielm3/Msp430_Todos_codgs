#include <msp430.h> 

// EletronWorld
// Jader Bernardo

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Parar watchdog timer

    P1DIR |=  BIT0;   // Define se bit entrada ou saida
    P1REN &= ~BIT3;   // Habilita resistor de pull-up
    P1OUT |= BIT3;   // Define estado inicial do port1

    P1IE  |= BIT3;    // Habilitando a interrup��o p/ P1.3
    P1IES |= BIT3;   // Defini��o da borda subida/descida
    P1IFG |= 0x00;   // Registrador referente a flag

    _enable_interrupts();   // Habilita as interrup��es

    while(1){}
}

// Defini��o do vetor de interrup��o
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void){
    P1OUT ^= BIT6;      // Troca o estado do led
    P1IFG |= 0x00;       // Zera a flag
}
