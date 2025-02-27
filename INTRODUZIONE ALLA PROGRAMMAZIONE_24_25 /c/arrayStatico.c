#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // Spazio per 99 caratteri + terminatore '\0'
    int currentLength = 0; // Indice per aggiungere caratteri

    // Inizializzare la stringa come vuota
    str[0] = '\0';

    // Aggiungere lettere con un ciclo for
    for (char c = 'A'; c <= 'H'; c++) {
        str[currentLength] = c;     // Aggiungi il carattere
        currentLength++;            // Incrementa la lunghezza
        str[currentLength] = '\0';  // Aggiorna il terminatore null
    }

    // Stampa il risultato
    printf("La stringa risultante è: %s\n", str);
    return 0;
}

// In questo esempio la memoria è statica ed è inizializzata per salvare 100 caratteri;
#