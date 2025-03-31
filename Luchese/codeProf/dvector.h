// #pragma once
#ifndef _DVECTOR_H_

#define _DVECTOR_H_



typedef int v_data;

typedef struct vector vector_t;

void v_print(vector_t* v);

// scrivi x in posizione i
void v_set(vector_t* v, size_t i, v_data x);

// leggi in posizione i
v_data v_get(vector_t* v, size_t i);

vector_t* v_create();

void v_free(vector_t *v);

void v_push_front (vector_t *A, int x);

// Concatenate
// dati due vector, ne creo un terso con la concatenazione 
// dei due

vector_t* v_concat (vector_t *A, vector_t *B);


void v_sort(vector_t *A);

void v_insert_sorted(vector_t *A, v_data x);


// altre fuzioni ...



#endif