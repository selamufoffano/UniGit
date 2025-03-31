/*
    Dati 3 interi corrispondenti a ore, minuti, e secondi, vizualizzare
    il numero di secondi trascorsi dall'inizio della giornata
*/
#include <stdio.h>

int main (void)
{
    int ore, min, sec;
    ore = 1;
    min = 0;
    sec = 0;
    // In un minuto ci sono 60secondi
    // In un ora ci sono 3600secondi


    // Quanti secondi ci sono dall'inizio della giornata?
    int secTot = ore*3600+min*60+sec; // i secondi totali dopo il calcolo
    printf("Secondi totali trascorsi inizio giornata: %d", secTot); 
    
    // STAMPO IN DOUBLE, dato che il valore potrebbe essere molto grande

    return 0;

}