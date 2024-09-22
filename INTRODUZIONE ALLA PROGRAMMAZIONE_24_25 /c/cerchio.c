/*
    Calcolare la circonferenza di un cerchio dato il suo raggio
*/
#include <stdio.h>

int main (void)
{
    /* Per calcolare la circonferenza del cerchio la formula è: 2*pi*r */
    // float r = 10; (nonstante sia float il compilatore lo considera come int, per evitar cio scrivo con "f")
    float r = 10;
    float pi = 3.14159;
    float circ = 2*pi*r;
    printf("Circonferenza: %f", circ);  
    
    // In linguaggio "C" prima di stampare dobbiamo specificare al compilatore il tipo di dato 
    // che vogliamo che venga restituito: Quindi
    // printf(circ); NON funziona a differenza di --> printf("%f", circ); 
    // --> printf("%f", circ); in questo modo il compilatore sa che deve resituire un valore di tipo float

    return 0;
}