#include <stdio.h>
#include <stdbool.h>

int main(void) { 
	// Trovare il massimo tra 3 numeri.
	int num1, num2, num3, max;
	printf("\ninserisci numero: "); scanf("%d", &num1);
	printf("\ninserisci numero: "); scanf("%d", &num2);
	printf("\ninserisci numero: "); scanf("%d", &num3);


	max = num1;
	if (num2>max) max = num2;
	if (num3>max) max = num3;
	
	/* altra soluzione
	if ( (num1 >= num2) && (num1 >= num3) ) max = num1;
	else if ( (num2 >= num1) && (num2 >= num3) ) max = num2;
	else max = num3;
	*/

	printf("il massimo è: %d \n", max);


	return 0; // termina l'esecuzione della funzione main


	bool a = false, b = true;

	if ( !a ) {
		printf("vera!! \n");
	} else {
		printf("falsa!! \n");
	}
	printf("Fine!!\n");


	return 0;

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


  return 0;
}
