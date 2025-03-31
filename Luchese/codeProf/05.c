#include <stdio.h>
#include <stdbool.h>
#include <math.h>


// dato un intero restituisce il successivo
int succ ( int x )
{
 	return x+1;
}

 // Scrivere una funzione che dati i coefficienti 
 // di un’equazione di secondo grado ax2+bx+c=0, 
 // ne visualizzi le soluzioni
void eq2 ( float a, float b, float c) {
	// ( -b +/- radice(b^2-4ac) ) / (2a)
	float delta = b*b - 4*a*c;
	if (delta < 0) {
		printf("Delta negativo: nessuna soluzione\n");
	}
	else 
		if (delta == 0) {
			float sol = -b / (2*a);
			printf("Delta nullo, una soluzione %f\n", sol);
		}
		else { //if (delta > 0) {
			float sol1, sol2;
			sol1 = (-b + sqrt(delta) ) / (2*a);
			sol2 = (-b - sqrt(delta) ) / (2*a);
			printf("Delta positivo, due soluioni %f  , %f\n", sol1, sol2);
		}
}

void eq2_v2 ( float a, float b, float c ) {
	// ( -b +/- radice(b^2-4ac) ) / (2a)
	float delta = b*b - 4*a*c;
	if (delta < 0) {
		printf("Delta negativo: nessuna soluzione\n");
		return;
	}
	if (delta == 0) {
		float sol = -b / (2*a);
		printf("Delta nullo, una soluzione %f\n", sol);
		return;
	}
	float sol1, sol2;
	sol1 = (-b + sqrt(delta) ) / (2*a);
	sol2 = (-b - sqrt(delta) ) / (2*a);
	printf("Delta positivo, due soluioni %f  , %f\n", sol1, sol2);
}


int main(void) { 


	float a = 1, b = 2, c = 3;
	eq2(a,b,c);






	return 0;

	int valore = succ(10);
	printf("valore %d \n", valore);


	return 0;

	// incrementi
	int val = 10;
	int nuovo =  (val = 73) *2 ;
	printf("val:   %d\n", val);
	printf("nuovo: %d\n", nuovo);
	if ( val = 5 ) {
		
	}


  	return 0;
}