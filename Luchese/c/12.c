#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>




/*
void print_array(int *a_begin, int *a_end) {
	printf("[");
	while ( a_begin != a_end ) {
		printf(" %d", *(a_begin) );
		a_begin++;
	}
	printf(" ]\n");
}*/

void print_array(int *v, size_t v_size) {
	printf("[");
	for (size_t i=0; i<v_size; i++) {
		printf(" %d", v[i] );
	}
	printf(" ]\n");
}
















// scrivere una funzione che dati due insiemi A e B
// memorizzati come array di interi
// restituisca un nuovo array con l'unione dei due insieme
// es.
// input  : A={1,2,3}  B={5,2,3,4}
// output : {1,2,3,4,5}

bool is_in( int x, int *v, size_t v_size) {
	for (size_t i=0; i<v_size; i++)
		if (v[i] == x)
			return true;
	return false;
}


void smart_copy( int *dest, size_t *dest_size, int *src, size_t src_size ) {
	// per ogni elemento di src
	for (size_t i=0; i<src_size; i++)
		// se e solo se src[i] NON E' in dest
		if ( ! is_in (src[i], dest, *dest_size) )
			dest[(*dest_size)++] = src[i]; // aggiungi alla fine di dest
}

// Callee allocated and returned
// il chiamante (caller) deve deallocare!!!
int * set_union (int *A, size_t A_size, int *B, size_t B_size,
				size_t * dest_size) {
	// preparo memoria per il risultato: dest
	int * dest = (int*) malloc ( (A_size+B_size)*sizeof(int) );
	if (!dest) exit(EXIT_FAILURE);
	*dest_size = 0;

	// copio A in dest
	smart_copy( dest, dest_size, A, A_size );

	// copio B in dest
	smart_copy( dest, dest_size, B, B_size);

	// restringo l'array
	dest = realloc(dest, (*dest_size)*sizeof(int));
	if (!dest) exit(EXIT_FAILURE);

	return dest;
}

// Caller ownership.
int * set_union_v2 (int *A, size_t A_size, int *B, size_t B_size,
				int *dest, size_t * dest_size) {
	*dest_size = 0;

	// copio A in dest
	smart_copy( dest, dest_size, A, A_size );

	// copio B in dest
	smart_copy( dest, dest_size, B, B_size);

	// restringo l'array
	dest = realloc(dest, (*dest_size)*sizeof(int));
	if (!dest) exit(EXIT_FAILURE);

	return dest;
}




// scrivere una funzione che dato un array di interi,
// restituisce un nuovo array che contiene gli
// elementi che appaiono almeno 2 volte
// es.
// input  : {1, 2, 3, 1, 4, 2, 3, -7, 3, 3}
// output : {1, 2, 3}
// l'ordinamento non conta.
int * dups_wrong(int *A, size_t A_size, size_t *dest_size) {
	int count[ 10000 ] = {0};
	for (size_t i=0; i<A_size; i++)
		count [ A[i] ] ++;

	int dups_count = 0;
	for (int i=0; i<10000; i++)
		if (count[i]>=2)
			dups_count++;

	int * dest = (int *) malloc (dups_count * sizeof(int));
	*dest_size = 0;
	for (int i=0; i<10000; i++)
		if (count[i]>=2)
			dest[ (*dest_size)++ ] = i;
	return dest;
}

int * dups(int *A, size_t A_size, size_t *dest_size) {
	int * dest = (int*) malloc ( A_size * sizeof(int)); // più di quel che serve
	if (!dest) exit(EXIT_FAILURE);

	*dest_size = 0; // importante 
	for (size_t i=0; i<A_size; i++) {
		// quando devo inserire A[i] in dest?
		// if ( is_in( A[i], &(A[i+1]), A_size-i-1 )  )
		if (  is_in( A[i], A+i+1, A_size-i-1 ) &&  // è presente nella parte rimanente
			 !is_in (A[i], dest, *dest_size) )
			dest[ (*dest_size)++ ] = A[i];
	}
	dest = realloc(dest, (*dest_size) *sizeof(int));
	if (!dest) exit(EXIT_FAILURE);
	return dest;
}


int main(void) {
	int lista[] = {1, 2, 3, 1, 4, 2, 3, -7, 3, 3};
	size_t dups_size;
	int * l2 = dups(lista, 10, &dups_size);
	print_array(l2, dups_size); 
	free(l2);
	return 0;




	int A[] ={1,2,3};
	int B[] ={5,2,3,4,1,7,9,123};

	size_t u_size;
	int * u = set_union(A, 3, B, 8, &u_size);
	// stampa il risultato
	print_array(u, u_size);
	
	free(u);

	size_t v_size;
	int * v = (int*) malloc( 100*sizeof(int) );
	v = set_union_v2(A, 3, B, 8, v, &v_size);
	// stampa il risultato
	print_array(v, v_size);
	
	free(v);



  	return 0;
}