#include <stdio.h>
#include <stdbool.h>
int is_prime(int n)
{
    // ES 1: Dato un intero N, calcolare la somma dei primi N numeri interi
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

int sommaNnaturali(int n)
{
    // Es 2: Dato un intero N, calcolare la somma dei quadrati dei primi N numeri interi
    /*
    n = 20
    0^0 = 1
    1^2 = 1 (1+1)
    2^2 = 4 (4+1)
    3^2 = 9 (4+1+9) ....
    */
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum = sum + (i * i);
        printf("%d \n", sum);
    }
}

int displayShorts(int n)
{
    // Es 3: Dati un intero N, visualizzare tutti i numeri dispari tra 0 e N
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            
        }
        else
        {
            printf("dispari %d \n", i);
        }
    }
}

int media(int a, int b)
{
    // ES 4: Dati due interi A e B, calcolare la media dei numeri nell’intervallo [A,B]

    /*
    a = 2, b= 10
    media = (2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10)/9
    */
    int aux = 0;
    int min, max;
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    int i = 0;
    int somma = 0;
    int count = 0;
    for (i = min; i <= max; i++)
    {
        count++;
        somma = somma + i;
        // printf("somma : %d count: %d \n", somma, count);
    }
    printf("somma : %d count: %d \n", somma, count);
    float media = somma / count;
    printf("Media: %f", media);
}

void display200_2200()
{

    // ES 5: Scrivere un programma che visualizzi  tutti i numeri tra 2000 e 2200 (estremi
    //  inclusi) che sono divisibili per 7 ma che non sono multipli di 5
    for (int i = 2000; i < 2200; i++)
    {
        if (i % 7 == 0 && i % 5 == 1)
        {
            printf("\n %d", i);
        }
    }
}

int resto_A_B(int a, int b)
{
    // Es 6: Dati due numeri interi A e B, calcolare il risultato di A/B e A%B usando solo le
    // operazioni di somma e sottrazione.
    int aux = 0;
    int min, max;
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    // La divisione 10/2, è uguale all'operazione di sottrazione
    // 10/2 = (10-2), (8-2), (6-2).....

    printf("Operazione di Disione\n");
    while (max > 0)
    {
        printf(" \n%d", max);
        max = max - min;
    }
    printf("\n\nOperazione Resto Zero\n");
    // Da completare...
}

int fattoriale(int n)
{
    // Dato N, calcolare il valore del fattoriale N!
    int fattoriale = 1;
    for (int i = 1; i <= n; i++)
    {
        // fattoriale = fattoriale * i;
        // si può anche scrivere in questo modo:
        fattoriale *= i; // sono la medisima operazione

        // printf(" \n%d", fattoriale);

        /* al psoto del print dentro la funzione posso fare il return
         della variabile (però devo chiamare printf dentro il main per
         vedere il valore)
        */
    }
    return fattoriale;
}

int fibonacci(int n)
{
    // Dato un intero N, calcolare l’N-esimo elemento della successione di Fibonacci
    // Fibo di 10: 0112357
    int t1 = 0, t2 = 1, succ;
    for (int i = 1; i <= n; i++)
    {
        printf("%d, ", t1);
        succ = t1 + t2;
        t1 = t2;
        t2 = succ;
    }
}

bool funzioneBool(){
    // Scrivere una funzione che restituisca true se e solo se esistono 2 interi 
    // positivi tali a,b tali che  𝑎2+𝑏2=25, e che restituisca false altrimenti

    for (int a = 0; a<= 25; a++)
    {
        for (int b = 0; b <= 25; b++)
        {
            bool exist = a*a + b*b == 25 || 
        }
        
    }
    


}

int main(void)
{
    /*int num = 7;
    bool result = is_prime(num);              // Chiamiamo la funzione con 7
    printf("%d, è primo? %d\n", num, result); // Stampa 1 se primo, 0 se non primo

    sommaNnaturali(20);

    displayShorts(20);
    media(2, 10);
    display200_2200();
    resto_A_B(15, 2);
    fibonacci(10);
   */
    printf("\n%d", fattoriale(7));
    return 0;
}