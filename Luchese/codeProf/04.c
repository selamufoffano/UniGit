#include <stdio.h>
#include <stdbool.h>

int main(void) { 

	// incrementi
	int val = 10;
	int nuovo = val++ + ++val;
	printf("%d\n", val);
	printf("%d\n", nuovo);


	return 0;

	// Dato in input un numero (positivo) intero <=255, 
	// visualizzare la sua rappresentazione binaria
	// 1 => 1
	// 2 => 10
	// 7 => 111
	int n;
	printf("inserisci un numero intero < 255:\n");
	scanf("%d", &n);
	if ( n >= 128 ) { n = n - 128; printf("1"); } else { printf("0"); }
	if ( n >= 64 ) { n = n - 64; printf("1"); } else { printf("0"); }
	if ( n >= 32 ) { n = n - 32; printf("1"); } else { printf("0"); }
	if ( n >= 16 ) { n = n - 16; printf("1"); } else { printf("0"); }
	if ( n >= 8 ) { n = n - 8; printf("1"); } else { printf("0"); }
	if ( n >= 4 ) { n = n - 4; printf("1"); } else { printf("0"); }
	if ( n >= 2 ) { n = n - 2; printf("1"); } else { printf("0"); }
	if ( n >= 1 ) { n = n - 1; printf("1"); } else { printf("0"); }
	printf("\n");

	printf("inserisci un numero intero < 255:\n");
	scanf("%d", &n);
	int pow2 = 128;
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	if ( n >= pow2 ) { printf("1"); } else { printf("0"); }
	pow2 = pow2 / 2; 
	printf("\n");

	printf("inserisci un numero intero < 255:\n");
	scanf("%d", &n);
	int pow = 128;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2; 
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("%d", n/pow); n -= (n/pow)*pow; pow /=2;
	printf("\n");


	return 0; // interrompe il programma

	// Date le lunghezze di tre segmenti, 
	// dire se questi possono formare un triangolo.
	// se la somma di due è maggiore del terzo, per ogni coppia
	int lato1, lato2, lato3;
	printf("Inserisci 3 lunghezze: \n");
	scanf("%d", &lato1);
	scanf("%d", &lato2);
	scanf("%d", &lato3);

	if ( (lato1+lato2 > lato3) && (lato1 +lato3 > lato2) && 
		 (lato2+lato3>lato1) )
		printf("SI!\n");
	else
		printf("NO!\n");


	return 0; // interrompe il programma

	if ( ( (0.1 + 0.1 + 0.1) == 0.3) /* == true */ )  
		printf("vera!\n");
	else
		printf("falsa!\n");
	
	/* modo corretto per confrontare due double / float
	double a, b; // se a > b
	if ( a-b < 0.0000000001 )
	*/

  	return 0;
}