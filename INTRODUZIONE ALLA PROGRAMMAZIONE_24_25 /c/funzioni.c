/*come si creare una funzione
La prima funzione che troviamo è la funzione MAIN
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