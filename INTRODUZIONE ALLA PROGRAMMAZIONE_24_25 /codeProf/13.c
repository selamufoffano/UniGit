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








int lungh(char *s) {
	int len = 0;
	while ( *s ) {
		s++;
		len++;
	}
	return len;
}

// data una stringa, dire se questa è palindroma
// es. "anna", "abcdcba"
bool palindroma (char *s) {
	int len = lungh(s);  // lunghezza della stringa
	// iterare la stringa carattere per carattere
	//    dall'innizio a metà
	for (int i=0; i<len/2; i++) { // occhio ai dispari !!!
	//    controllo che i'esimo carattere sia uguale al ult-i-mesimo
	//    se è diverso? ritorno false
		if ( s[i] != s[len-i-1] )
			return false;
	}
	return true;
}


// Scrivete una funzione chiamata all_letters che, 
// data una stringa s, restituisce true se s usa tutte le lettere
//  dell’alfabeto inglese, false altrimenti. 
// Assunzione: s contiene solo caratteri alfabetici minuscoli.
// es. "the quick brown fox jumps over the lazy dog" => true
// es. "i have no idea if this contains all the letters" => false

bool is_in(char x, char * s) {
	while (*s) {
		if (x == *s) return true;
		s++;
	}
	return false;
}
bool all_letters_1(char * s) {
	char *alphabet = "abcdefghijklmnoprstuvwxyz";
	char *letter = alphabet;
	while (*letter) {
		if ( ! is_in(*letter, s) )
			return false;
		letter++;
	}
	return true;
}
bool all_letters_2(char * s) {
	for (char letter = 'a'; letter <= 'z' ; letter++) {
		if ( ! is_in(letter, s) )
			return false;
	}
	return true;
}
bool all_letters(char * s) {
	int letters[26] = {0};
	while (*s) {
		letters [ *s - 'a' ] = 1; // l'ho vista
		s++;
	}
	for (int i=0; i<26; i++)
		if (letters[i]==0)
			return false;
	return true;
}


int main(int argc, char *   argv[]) {
	int num_players = atoi( argv[1] );
	printf("num players %d\n", num_players);


	return 0;

	printf("%d \n", all_letters("the quick brown fox jumps over the lazy dog"));
	printf("%d \n", all_letters("no way!"));


	return 0;

	printf("lungh %d \n", lungh("123456"));

	printf("%s è palindroma: %d \n", "anna", palindroma("anna"));

	return 0;

	// stringhe !!!!
	char single_c = 'x';
	char *a = "Hello!!!!!!!"; // automaticamente viene aggiunto '\0'
	char b[]  = "Hello!";   // tot 7 caratteri  // automaticamente viene aggiunto '\0'
	char b2[] = {'H', 'e', 'l', '\0', 'l', 'o', '!', '\0'}; // == 0 

	a[0] = 'X';
	b[0] = 'X';

	printf("%s \n", a);
	printf("%s \n", b);
	// printf("%s \n", b2);



  	return 0;
}