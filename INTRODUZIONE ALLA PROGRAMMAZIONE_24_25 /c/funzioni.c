/*come si creare una funzione
La prima funzione che troviamo è la funzione MAIN

Se all'interno del codice ci sono ripetizoni di codice allora deve essere sostituito con una funzione
*/

#include <stdio.h>

int succ (int a)
{
    return a+1;
}

void chiama()
{
    printf("Ciao");
    return;
}

int main (void)
{
    chiama();
    int valore = succ(10);
    printf("%d", valore);
}