#include <stdio.h>
/*
Link utili:
- https://symbl.cc/en/unicode-table/#playing-cards
*/

//Malloc(siezeof(int)*lenth)
//calloc

// Print TitleGame
// Print Regole di gioco
// Inserire il numero di Utenti In gioco
/*
    0. Input numero giocatori, Distribuzione carte (2 per ciascun giocatore). Una carta coperta ed una scoperta
    1. Funzione random per selezionare il giocatore di partenza
    2. Visualizzo le regole applicabili alle carte (l'utente dovrà selezionare a chi applicare e cosa fare),
        alla fine stampa cosa l'utente ha deciso di fare
    3. calcolo punti
*/

void titleGame()
{
}

// Funzione Regole di gioco
void rules()
{
    printf("unicode_to_utf8(36)\n");
}

int numPlayerCard(int nPlayer)
{
}

void Shuffle()
{
}

void giveCard()
{
}

void points()
{
}

void setStartPlayer()
{
}

void startGame()
{
    // Quanri giocatori ci sono (Mi 2, max 20)
}

void menuGame()
{
    // stampa tutte opzioni gioco
}

void stampaListeGiocatori(char **liste_giocatori[], int num_giocatori, int num_punteggi=7)
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

int main(void)
{
    stampaListeGiocatori()
}