#include <stdio.h>
#include <stdlib.h>

// Dichiarazione della funzione esterna
void stampaListeGiocatori(int **liste_giocatori, int num_giocatori, int num_punteggi); // lo lascio dichiarato così non ho nessun obbligo dove posizonare il main
int numPlayer(int nPlayer);


int main()
{
    int num_giocatori = 3; // Supponiamo di avere 3 giocatori
    int num_punteggi = 5;  // Ogni giocatore avrà una lista di 5 punteggi

    // Allocazione dell'array di puntatori
    int **liste_giocatori = malloc(num_giocatori * sizeof(int *));
    if (liste_giocatori == NULL)
    {
        fprintf(stderr, "Errore di allocazione della memoria\n");
        return 1;
    }

    // Allocazione delle liste per ogni giocatore
    for (int i = 0; i < num_giocatori; i++)
    {
        liste_giocatori[i] = malloc(num_punteggi * sizeof(int));
        if (liste_giocatori[i] == NULL)
        {
            fprintf(stderr, "Errore di allocazione della memoria\n");
            return 1;
        }
    }

    // Esempio di assegnazione dei valori
    for (int i = 0; i < num_giocatori; i++)
    {
        for (int j = 0; j < num_punteggi; j++)
        {
            liste_giocatori[i][j] = i + j; // Assegna valori a ciascun punteggio
        }
    }

    // Chiamata alla funzione esterna per stampare le liste
    stampaListeGiocatori(liste_giocatori, num_giocatori, num_punteggi);

    // Dealloca la memoria
    for (int i = 0; i < num_giocatori; i++)
    {
        free(liste_giocatori[i]);
    }
    free(liste_giocatori);

    return 0;
}

int numPlayer(int nPlayer)
{
}

// Definizione della funzione esterna
void stampaListeGiocatori(int **liste_giocatori, int num_giocatori, int num_punteggi)
{
    for (int i = 0; i < num_giocatori; i++)
    {
        printf("Giocatore %d: ", i + 1);
        for (int j = 0; j < num_punteggi; j++)
        {
            printf("%d ", liste_giocatori[i][j]);
        }
        printf("\n");
    }
}