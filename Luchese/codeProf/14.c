#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>




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




// date due stringhe a e b,
// dire quante volte a occorre in b
// anche con sovrapposizioni
// ed. "abab" 3 volte in "ababxabababx"
//                        ^    ^ ^


// data una stringa, restituire una nuova stringa
// dopo aver eleminato tutto quello che non è
// racchiuso tra parentesi
// es.  "(I ) do not (Love ) wasting my time at (Coding) badly" => "I Love Coding" 
// non ci sono parentesi annidate, e sono sempre corrette
 
char * parentheses_2(char *s) {
	// allocare memoria per la nuova stringa dest
	char * dest = (char*) malloc(strlen(s)-2+1); //  al massimo pari alla lunghezza di s - 2 + 1
	if (!dest) exit(EXIT_FAILURE);

	int j = 0;           // dest è vuota, la prima posizione buona è j=0 
	bool dentro = false; // all'inizio sono fuori dalle parentesi
	// scandire s carattere per carattere c, 
	for (int i=0; i<strlen(s); i++) {
		char c = s[i];
		
		if (c=='(')        //		se c == '(', allora sono dentro le parentesi dentro = true
			dentro = true; //                   ma '(' non va copiata in dest
		else if (c==')')   //      se c == ')', allora sono fuori dalla parentesi dentro = false
			dentro = false;
		else
			if (dentro==true)   // 		se dentro==true, copiamo il carattere nella nuova stringa
				dest[j++] = c;  //          nella posizione j, e incrementiamo j si 1
	//      altrimenti, lo ignoriamo: non faccio niente		
	}
	dest[j++] = '\0';  // aggiungi terminatore
	// restituiamo la nuova stringa dest
	dest = realloc ( dest, j);
	return dest; 
}

char * parentheses(char *s) {
	// allocare memoria per la nuova stringa dest
	char * dest = (char*) malloc(strlen(s)-2+1); //  al massimo pari alla lunghezza di s - 2 + 1
	if (!dest) exit(EXIT_FAILURE);

	char *s_ptr = s, *dest_ptr = dest;
	bool dentro = false; // all'inizio sono fuori dalle parentesi
	// scandire s carattere per carattere c, 
	while ( *s_ptr ) {
		if (*s_ptr=='(')        //		se c == '(', allora sono dentro le parentesi dentro = true
			dentro = true; 		//                   ma '(' non va copiata in dest
		else if (*s_ptr==')')   //      se c == ')', allora sono fuori dalla parentesi dentro = false
			dentro = false;
		else
			if (dentro==true)   // 		se dentro==true, copiamo il carattere nella nuova stringa
				*(dest_ptr++) = *s_ptr;  //          nella posizione j, e incrementiamo j si 1

		s_ptr++;
	}
	*(dest_ptr++) = '\0';  // aggiungi terminatore
	// restituiamo la nuova stringa dest
	dest = realloc ( dest, dest_ptr-dest);
	return dest; 
}







// data una matrice num_studenti x materia contenente i voti ricevuti
// 1) calcolare il voto medio per materia
// 2) calcolare quante materie hanno voto medio >= 28

float * voti_medi(int *voti, int num_studenti, int num_materie) {

	float * medie = (float*) malloc(num_materie * sizeof(float));
	if (!medie) exit(EXIT_FAILURE);

	for (int mat=0; mat<num_materie; mat++) {
		medie[mat] = 0.0f;
		for (int stud=0; stud<num_studenti; stud++) 
			medie[mat] += voti[ stud*num_materie + mat ];
		medie[mat] /= (float)num_materie;
	}
	return medie;
}


int main(int argc, char *   argv[]) {

	int voti[2][3] = { {30, 28, 25 },
	                   {30, 25, 30} };

	float *v = voti_medi( (int*)voti, 2, 3);
	// float *v = voti_medi( &(voti[0][0]), 2, 3);




	return 0;

	char *s = "(I ) do not (Love ) wasting my time at (Coding) badly";
	char *t = parentheses(s);
	printf("%s \n", t);
	free(t);

  	return 0;
}