#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "dvector.h"



struct vector {
    v_data *data;
    size_t size;
};

// sort ricorsivo, di un array 
void _sort_rec(v_data *data, size_t size) {
    if (size<=1)
        return;

    // trovo il più piccolo
    size_t min_i = 0;
    for (size_t i=1; i<size; i++)
        if (data[i]<data[min_i])
            min_i = i; 
    // scambio il min in testa
    v_data aux = data[0];
    data[0] = data[min_i];
    data[min_i] = aux;
    // ordino dal secondo i poi
    _sort_rec ( data+1, size-1 );
}


void v_sort(vector_t *A) {
    _sort_rec(A->data, A->size);
}


vector_t* v_concat_v2 (vector_t *A, vector_t *B) {
    size_t new_size  = A->size + B->size;
    v_data* new_data = (v_data*) malloc (new_size*sizeof(v_data) );
    // scorro gli elementi di A e li copio in new_data
    for (size_t i=0; i<A->size; i++)
        new_data[i] = A->data[i];
    // scorro gli elementi di B e li copio in new_data
    for (size_t i=0; i<B->size; i++)
        new_data[ A->size + i ] = B->data[i];

    vector_t* new_v = (vector_t*) malloc(sizeof(vector_t));
    if (!new_v) exit(EXIT_FAILURE);

    new_v -> data = new_data;
    new_v -> size = new_size;

    return new_v;
}

vector_t* v_concat_v2 (vector_t *A, vector_t *B) {
    vector_t* new_v = v_create();
    for (size_t i=0; i<A->size; i++)
        v_push_back(new_v, A->data[i]);
    for (size_t i=0; i<B->size; i++)
        v_push_back(new_v, B->data[i]);

    return new_v;
}



bool _check_index(vector_t* v, size_t i){
    return i < v->size;
}


void v_set(vector_t* v, size_t i, v_data x){
    if ( _check_index(v,i) )
        v->data[i] = x;
    else 
        printf("Error: index out of bounds in v_set.\n");
}


v_data v_get(vector_t* v, size_t i){
    if ( _check_index(v,i) )
        return v->data[i];
    else 
        printf("Error: index out of bounds in v_get.\n");    
}

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
    if (A->data)
        free(A->data);   // free old memory
    A->data = nuovo; // point to new memory
    A->size++;       // new size
}
