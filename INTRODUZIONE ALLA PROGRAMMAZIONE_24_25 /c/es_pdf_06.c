#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int num = 7;
    bool result = is_prime(num);          // Chiamiamo la funzione con 7
    printf("%d, è primo? %d\n", num, result); // Stampa 1 se primo, 0 se non primo

    return 0;
}

int is_prime(int n)
{
    // Un numero è primo se è divisibile "1" e per se stesso
    // posso fare un contatore se è maggiore di due allora non è un primo
    bool found = false;
    // esegue il ciclo fino a quando found è vera
    // se non mettessimo !found non entrerebbe mai nel ciclo
    for (int i = 2; !found && i < n; i++)
    {
        // la logica della risuoluzione è:
        // dato che un numero è primo se divisibile per "1" e se stesso allora non li consideriamo
        if (n % i == 0)
        {
            found = true;
        }
    }
    return !found; // ci dice vero o falso
}
