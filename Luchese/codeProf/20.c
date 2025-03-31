#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#include "dvector.h"


int main() {

/*
    vector_t * mazzo = v_create();
    v_shuffle(mazzo);
    carta* c = v_pop(mazzo); // la carta in cima al mazzo
*/

    vector_t *A = v_create();        
    v_print(A);

    v_push_front( A, 99);
    v_print(A);

    v_push_front( A, 1);
    v_print(A);

    v_set(A, 0, 55);
    v_print(A);
   
    v_set(A, 20, 55);
    v_print(A);

    v_get(A, 20);
    printf("%d\n", v_get(A, 1));

    v_free(A);


    return 0;
}

