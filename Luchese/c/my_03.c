#include <stdio.h>
int main(void)
{
    // Trovare il massimo tra 3 numeri.
    /*
    int n1, n2, n3;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    printf("n1: %d, n2: %d, n3: %d\n", n1, n2, n3);
    int nMax = n1;
    if (n2 > nMax)
        nMax = n2;
    if (n3 > nMax)
        nMax = n3;

    printf("Max: %d", nMax);
    return 0;

    */
   /*
    int y, w, d;
    /* 
    y = 365 -> giorni
    w = 7 -> giorni
    d = 1 -> giorno
    *
    printf("Anni: "); scanf("%d", &y);
    printf("Settimane: "); scanf("%d", &w);
    printf("Giorni: "); scanf("%d", &d);
    int gTot = (y*365)+(w*7)+d;
    printf("Ci sono: %d giorni", gTot);
    return 0;
    */

    // Scrivere un programma C che dato un numero
    // di giorni specificato dall’utente,
    // calcola a quanti anni, settimane, giorni corrispondono
    	int input_days, years, weeks;
	scanf("%d", &input_days);
	years = input_days / 365;
	input_days = input_days % 365;
	weeks = input_days / 7;
	input_days = input_days % 7;
	printf("years: %d , weeks: %d, days %d.\n",
	 			years, weeks, input_days);

}