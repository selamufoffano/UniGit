/*
    Scambia i valori di A e B
*/
#include <stdio.h>

int main (void)
{
    int a, b, aux;
    a = 12;
    b = 3;
    printf("Valore di A prima dello scambio: %d\nValore di B prima dello scambio: %d\n", a, b);

    // io voglio che la variabile "a", assuma il valore della variabile "b" e viceversa
    // per far ciò devo creare una ternza variable che mi permette di scambiare "aux"
    aux = b;
    b = a;
    a = aux;

    printf("Valore di A dopo lo scambio: %d\nValore di B dopo lo scambio: %d\n", a, b);
    return 0;
}