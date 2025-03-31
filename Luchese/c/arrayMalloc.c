#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main_V0() {
    int maxLength = 100; // Dimensione massima della stringa
    char *str = (char *)malloc(maxLength * sizeof(char)); // Allocare memoria
    int currentLength = 0; // Indice per aggiungere caratteri

    if (str == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    // Inizializzare la stringa come vuota
    str[0] = '\0';

    // Aggiungere lettere con un ciclo for
    for (char c = 'a'; c <= 'e'; c++) {
        str[currentLength] = c;     // Aggiungi il carattere
        currentLength++;            // Incrementa la lunghezza
        str[currentLength] = '\0';  // Aggiorna il terminatore null
    }

    // Stampa il risultato
    printf("La stringa risultante è: %s\n", str);

    // Liberare la memoria allocata
    free(str);
    return 0;
}

int main (void) {
    int maxStr = 100;
    
}