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

float erone(float z, int N) { 
	float x_now = 2.0f; 
	for (int i=0; i<N; i++)
		x_now = 0.5 * ( x_now + z / x_now ); 
	return x_now;
}

float erone_at_home(float z, float tol) { 
	float x_now = 2.0f; 
	for (int i=0; i<1000000; i++) {
		// prepara per questa iterazione !!!!
		float x_old = x_now;
		x_now = 0.5 * ( x_old + z / x_old ); 
		if ( fabs(x_now-x_old) < tol );
			// Ho finito !!!
	}
	return x_now;
}

int main(void) { 
	printf("%f\n", erone(1684765, 0.0001));

	//printf("%d\n", f());

	// printf("%d\n", fact(4)); // 3*2*1

  	return 0;
}