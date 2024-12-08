#include <stdio.h>

int main(void)
{
    /*
    // scambiare due valori a, b
    int a, b, aux;
    a = 10;
    b = 20;
    printf("%d, %d \n", a, b);
    aux = a;
    a = b;
    b = aux;
    printf("%d, %d \n", a, b);
    */

    /* Dati 3 interi corrispondenti a ore, minuti e secondi, visualizzare il numero di secondi trascorsi dall’inizio della giornata
    int h, m, s;
    // h = 60m
    // 1m = 60s
    h = 10;
    m = 20;
    s = 40;
    int totS = (h * 3600) + (m * 60) + s;
    printf("ci sono: %d", totS);
    */

    /* Calcolare la circonferenza di un cerchio dato il suo raggio */
    int r = 30;
    double pi = 3.14;
    // forumala circonferenza: 2pir
    double circonferenza = 2 * pi * r;
    printf("%f", circonferenza);
}