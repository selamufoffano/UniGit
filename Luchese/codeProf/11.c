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


// scrivere una funzione che dato un array di interi,
// restituisce un nuovo array che contiene gli
// elementi che appaiono almeno 2 volte
// es.
// input  : {1, 2, 3, 1, 4, 2, 3, -7}
// output : {1, 2, 3}
// l'ordinamento non conta.





// scrivere una funzione che dato un array di interi,
// restituisce un nuovo array senza i duplicati
// es.
// input  : {1, 2, 3, 1, 4, 2, 3, -7}
// output : {1, 2, 3, 4, -7}
// l'ordinamento non conta.

bool is_in(int x, int *v, size_t v_size){
	for (size_t i=0; i<v_size; i++)
		if (v[i] == x)
			return true;
	return false;
}

int * dedup(int *v, size_t v_size, size_t *new_size) {
	// selezionati = insieme vuoto
	size_t selezionati_size = 0;
	int * selezionati = (int*) malloc (v_size*sizeof(int));
	if ( !selezionati ) 
		exit( EXIT_FAILURE );
	// per ogni elemento di v
	for (size_t i=0; i<v_size; i++) {
		// se l'elemento non è tra i selezionati
		if ( !is_in(v[i], selezionati, selezionati_size) ) {
			// aggiungo ai selezionati
			selezionati[selezionati_size++] = v[i];
		}
	}
	// restituisco i selezionati
	*new_size = selezionati_size;
	return selezionati;
}






// Dato un array di interi,
// trovare la sottosequenza di valori consecutivi
// nell'array che ha somma massima e restituirne la somma
// es.
// input  : {1, -20, 3, 5, -4, 2, 3, -7}
// output : 9 (da 3 a 3)

int somma(int *v, int start, int end) {
	int somma = 0;
	for (int i=start; i<=end; i++)
		somma += v[i];
	return somma;
}

int max_subarray_0(int *v, int v_size) {
	// miglior_somma_trovata
	int best_sum = 0; // la sottosequenza può essere vuota
	
	for (int start=0; start<v_size; start++) { // per ogni possibile inizio
	   	
		for (int end=start+1; end<v_size; end++) { // per ogni possibile fine
	      	
			int sum = somma(v, start, end); // calcolo la somma da start a end
		  	
		  	if (sum > best_sum) // aggiorno la miglior_somma_trovata
		  		best_sum = sum;
		}
	}
	
	return best_sum; // restituisci miglior_somma_trovata
}

// soluzione con un ciclo for in meno
int max_subarray(int *v, int v_size) {
	// miglior_somma_trovata
	int best_sum = 0; // la sottosequenza può essere vuota
	for (int start=0; start<v_size; start++) { // per ogni possibile inizio
	   	int sum = 0;
		for (int end=start; end<v_size; end++) { // per ogni possibile fine
	      	sum += v[end];		  	
		  	if (sum > best_sum) // aggiorno la miglior_somma_trovata
		  		best_sum = sum;
		}
	}
	
	return best_sum; // restituisci miglior_somma_trovata
}

int main(void) {
	int w[] = {1, 2, 3, 1, 4, 2, 3, -7};
	size_t w2_size;
	int * w2 = dedup(w, 8, &w2_size);
	print_array(w2, w2_size);

	free(w2);

	return 0;



	int v[] =  {1, -20, 3, 5, -4, 2, 3, -7};
	int max_somma = max_subarray(v, 8);
	printf("La somma massima è %d\n", max_somma);

  	return 0;
}