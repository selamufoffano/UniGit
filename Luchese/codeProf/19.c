#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
// Strutture Dati

// Abstract Data Structures: vector
// semantica e comportamento
// .... l'implentazione è un dettaglio

int A[10];

{1,2,3} => {99,1,2,3} => {99,1,2,3, 100} => {99,1,3}

//
push_front(A, 99);
push_back(A, 99);
remove_even(A);

*/








// void cuori(struct carta * c) {
//     // (*c).seme = 'c';
//     c->seme = 'c';
// }

typedef
struct carta {
    int valore; // da 1 a 10
    char seme;  // cuori, fiori, ecc ecc
    int * x;
} carta_t;


// abstarct data type : Vector (int)
// array, ma in cui posso aggiungere ed eliminare elementi

// push_front(A,x) : aggiunge x in testa ad A
// push_front( {1,2,3}, 99 ) => {99,1,2,3}

typedef int v_data;

typedef
struct vector {
    v_data *data;
    size_t size;
} vector_t;


void v_print(vector_t* v) {
    printf("[");
    for (size_t i=0; i<v->size; i++)
        printf(" %d", v->data[i] );
    printf(" ]\n");
}


vector_t* v_create() { // creto un vector vuoto
  vector_t* nuovo = (vector_t*) malloc( sizeof(vector_t));
  nuovo->data = NULL; // 0 puntatore "vuoto" non valido
  nuovo->size = 0;
  return nuovo;
}

void v_free(vector_t *v) {
    if (v->size>0)
        free(v->data);
}

void v_push_front (vector_t *A, int x) {
    // modifica A aggiungendo x
    // at home! provare con realloc
    int * nuovo = (int*) malloc ( (A->size+1) * sizeof(int) );
    nuovo [0] = x;
    for (size_t i=0; i<A->size; i++)
        nuovo[i+1] = (*A).data[i];
    free(A->data);   // free old memory
    A->data = nuovo; // point to new memory
    A->size++;       // new size
}



int main() {
    vector_t *A = v_create();        
    v_print(A);

    v_push_front( A, 99);
    v_print(A);

    v_push_front( A, 1);
    v_print(A);
   
    v_free(A);



/*
    int z = 10;
    carta_t b = {7, 'c', &z};

    // shallow copy
    struct carta c = b;

    *(c.x) = 9;

    printf("carta b: %d, %c, %d \n", 
        b.valore, b.seme, *(b.x));

    printf("carta c: %d, %c, %d \n", 
        c.valore, c.seme, *(c.x)); 

    // deep copy



    // printf("carta b: %d, %c \n", b.valore, b.seme);

    // cuori( &b );
    // printf("carta b: %d, %c \n", b.valore, b.seme);
    


    //printf("carta c: %d, %c \n", c.valore, c.seme);
*/
/*
    struct carta c;
    struct carta b = {7, 'c'} ;

    struct carta x = b; // assegnamento

    x.valore = 99;

    printf("carta b: %d, %c \n", b.valore, b.seme);
    printf("carta x: %d, %c \n", x.valore, x.seme);

    struct carta mazzo[3] = { {7, 'c'} , {8, 'p'} ,
                              {1, 'f'} };

    printf("seconda carta: %d, %c \n", mazzo[1].valore,
                                        mazzo[1].seme);

    struct carta * x_p = &x;

    // (*x_p).seme = 'q';
    x_p->seme = 'q';

    printf("carta x: %d, %c \n", x.valore, x.seme);
*/
    return 0;
}

