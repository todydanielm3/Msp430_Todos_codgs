//Remo��o de Rebotes

// O modificador volatile diz ao compilador que a vari�vel em quest�o pode ser alterada sem que este seja avisado.
//Isto evita "bugs" que poderiam ocorrer se o compilador tentasse fazer uma otimiza��o no c�digo que n�o � segura quando a mem�ria � modificada externamente.

#include <msp430.h> 

void debounce();

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

//congigura��o dos pinos de entrada
    P1DIR   |=  BIT0;   //zera o led vermelho
    P1DIR   &= ~BIT1;   //zera o bota�o S1
    P1REN   |=  BIT1;   //habilita o resistor pull down/pull up
    P1OUT   |=  BIT1;   //seleciona pull down

 //LOOP
    while(1){
        debounce();
        if((P1IN & BIT1)==0){//verifiva se o bot�o S1 est� precionado
            P1OUT   ^= BIT0;
            debounce();
       }
        else{
            P1DIR  |=  BIT0;

    }

    return 0;
}

void debounce(){

volatile unsigned int i;    // Declara a vari�vel i como sem sinal (unsigned) e usa o modificador volatile para previnir otimiza��o do compilador

i = 10000;

            do{
                i--;
            }while(i != 0);              // Esta � uma forma simples de temporizar
   }





