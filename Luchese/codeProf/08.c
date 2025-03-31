#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// scrivere una funzione che calcoli il fattoriale 
// di un intero dato N
// 10! = 10*9*8*7*......*1
//                       ^i
unsigned long int fact(unsigned long int N) 
{
	unsigned long int fattoriale = 1;
	for( unsigned long int i=N; i>=1 ; i--)
		fattoriale *= i;
	return fattoriale;
}

// Scrivere una funzione che restituisca true 
// se e solo se esistono 2 interi positivi a,b 
// tali che a^2+b^2=25, e che restituisca false altrimenti.
bool f_v2()
{
	// brute force
	// (a,b) => (a:1,b:1) (a:1,b:2) (a:1, b:3).... (2,1) (2,2) (2,3)...
	// sqrt(25) ???? 25/2 ???
	for (int a=1; a<=25; a++) {				// a = 1, a<=25 ?
		for (int b=1; b<=25; b++) {         // b = 1, b<25 ?
			bool exist = ( a*a + b*b == 25 ); // false
			if (exist) return true;
			// NO !!!!! else return false; // ????
		}
	}
	return false;
}

bool f_v3 ()
{
	// brute force
	// (a,b) => (a:1,b:1) (a:1,b:2) (a:1, b:3).... (2,1) (2,2) (2,3)...
	bool exist = false;
	for (int a=1; !exist && a<=sqrt(25); a++) {	   // a = 1, a<=25 ?
		for (int b=1; !exist && b<=sqrt(25); b++) {  // b = 1, b<25 ?
			exist = exist || ( a*a + b*b == 25 ); 
		}
	}
	return exist;
}
bool f()
{
	// brute force
	// (a,b) => (a:1,b:1) (a:1,b:2) (a:1, b:3).... (2,1) (2,2) (2,3)...
	// no a (1,N) e (N,1)
	// tutte le coppie tali che a <= b sempre
	bool exist = false;
	for (int a=1; !exist && a<=sqrt(25); a++) {	   // a = 1, a<=25 ?
		for (int b=a; !exist && b<=sqrt(25); b++) {  // b = 1, b<25 ?
			exist = exist || ( a*a + b*b == 25 ); 
		}
	}
	return exist;
}

// todo senza un for, da verificare .....
bool f_no_for()
{
	bool exist = false;
	for (int a=1; !exist && a<=sqrt(25); a++) {	 
		int b_al_quadrato = 25-a*a;
		exist = exist || 
		( sqrt(b_al_quadrato) == round(sqrt(b_al_quadrato)) ); 
	}
	return exist;
}

// erone radice quadrata
// x_0 = stima
// x_new = 0.5 * ( x_now + z / x_now )
// 10 iterazioni fino a x_10

float erone_v2(float z, int N) { // z = 16
	float x_0 = 2.0f;
	float x_new, x_now = x_0; 
	for (int i=0; i<N; i++) {
		x_new = 0.5 * ( x_now + z / x_now ); 
		x_now = x_new;  // prepara per la prossima iterazione
		// printf("--- %f\n", x_new);                      
	}
	return	x_new;
}

float erone_v3(float z, int N) { // z = 16
	float x_now = 2.0f; 
	for (int i=0; i<N; i++) {
		// prepara per questa iterazione !!!!
		float x_old = x_now;
		x_now = 0.5 * ( x_old + z / x_old ); 
	}
	return x_now;
}

float erone_v4(float z, int N) { 
	float x_now = 2.0f; 
	for (int i=0; i<N; i++)
		x_now = 0.5 * ( x_now + z / x_now ); 
	return x_now;
}

float erone_v5(float z, float tol) { 
	float x_now = 2.0f; 
	float improvement = tol+1; // assicurati di entrare nel loop 
	for (int i=0; !(improvement < tol) && i<1000000; i++) {
		float x_old = x_now;
		x_now = 0.5 * ( x_old + z / x_old ); 
		improvement = fabs(x_now-x_old);
	}
	return x_now;
}

float erone(float z, float tol) { 
	float x_now = 2.0f; 
	float improvement = tol+1.0f; // assicurati di entrare nel loop 
	// for ( ; !(improvement < tol) ; ) {
	while ( !(improvement < tol) ) {
		float x_old = x_now;
		x_now = 0.5 * ( x_old + z / x_old ); 
		improvement = fabs(x_now-x_old);
	}
	return x_now;
}

/* dato il lato scacchiera N, visualizzare una scacchiera
 se N = 6
# # # 
 # # #
# # # 
 # # #
# # # 
 # # #
*/
void scacchiera_v0 (int N) {
	for (int row=1; row<=N; row++) { // righe
		for (int col=1; col<=N; col++) { // colonne
			if (row%2==0)
				if (col%2==0) printf("#");
				else printf(" ");
			else
				if (col%2==0) printf(" ");
				else printf("#");
		}
		printf("\n");
	}
	printf("\n");printf("\n");
}

void scacchiera_v1 (int N) {
	char white = ' ', black = '#';
	for (int row=1; row<=N; row++) { // righe
		for (int col=1; col<=N; col++) { // colonne
			if (col%2==0) printf("%c", white);
			else printf("%c", black);
		}
		char aux = white;
		white = black;
		black = aux;
		printf("\n");
	}
	printf("\n");printf("\n");
}

void scacchiera (int N) {
	char white = ' ', black = '#';
	for (int row=1; row<=N; row++) { // righe
		for (int col=1; col<=N; col++) { // colonne
			if ( (row+col)%2==0 ) 
				printf("%c", white);
			else 
				printf("%c", black);
		}
		printf("\n");
	}
	printf("\n");printf("\n");
}
void g () {
	int x = 10;
	int *z = &x;
	(*z)++;
	x--;
	printf("%d\n", x);
}

void inc(int *v) {
	*v = *v + 1;
}





void hhh() {
	int x = 10;
	int * p_x = & x;
	int ** p = & p_x; 
	//int z = 9;
	// *p = &z;
	**p = 7; 
}
















int * p_next(int z) {
	int next = z+1;
	return &next; // int *
}

int main(void) { 

	int * n = p_next(10);
	//*n = 99;
	printf("%d \n", *n);







	return 0;
	int x = 10;
	inc( &x );
	printf("%d\n", x);
	printf("size of int %d\n", sizeof(int));
	printf("size of int* %d\n", sizeof(int*));

	// g ();

	// scacchiera(6);
	// printf("%f\n", erone(144.0f, 0.0001f) );

	//printf("%d\n", f());

	// printf("%d\n", fact(4)); // 3*2*1

  	return 0;
}