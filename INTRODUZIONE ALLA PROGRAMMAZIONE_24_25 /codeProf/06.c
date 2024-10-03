#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// dato un intero N, dire se N è primo
// primo se gli unici divisori sono 1 e se stesso (N)
bool is_prime_wrong (int N) {
	bool found = false;
//	for (int div=2; div<=N-1; div++) {
	for (int div=2; div<N; div++) {
		if ( N%div == 0 ) {
			// trovato un divisore !!
			found = true;
		} else {
			// no, non è un divisore
			found = false;
		}
	}
	bool prime = !found; // found==false;
	return prime;
}

bool is_prime_V2 (int N) {
	bool found = false;
	for (int div=2; div<N; div++) {
		bool divisore = N%div == 0;
		found = found || divisore;
	}
	bool prime = !found; // found==false;
	return prime;
}

bool is_prime_V3 (int N) {
	bool found = false;
	for (int div=2; div<N; div++) {
		found = found || N%div == 0;
	}
	return !found; // found==false;
}

bool is_prime_V4 (int N) {
	bool found = false;
	for (int div=2; div<N; div++) {
		found = found || N%div == 0;
		if (found) return false;
	}
	return !found; // found==false;
}

bool is_prime (int N) {
	bool found = false;
	for (int div=2; !found && div<N; div++) {
		found = found || N%div == 0;
	}
	return !found; // found==false;
}



// Dato un intero N, calcolare la somma dei primi N numeri interi
int f (int N) {
	int somma_parziale = 0;
	for (int i=1; i<=N; i++) {
		somma_parziale = i + somma_parziale;
		// printf("i:%d   - somma_parziale:%d\n", i, somma_parziale);
	}
	return somma_parziale;
}



int main(void) { 

	printf("11 è primo : %d\n", is_prime(11));
	printf("1100000000 è primo : %d\n", is_prime(1100000000));

	return 0;
	printf("risultato %d\n", f(10) );

  	return 0;
}