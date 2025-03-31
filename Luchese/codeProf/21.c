#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// tipo
struct node {
    int data;
    struct node * next;
};

typedef struct node list_t;

typedef struct node* LINK; // libro di testo

//list_t* l;
//LINK l;

// creazione
list_t* l_create_node(int val) {
    list_t *n = (list_t*) malloc (sizeof(list_t));
    if (!n) exit(EXIT_FAILURE);
    n->data = val;
    n->next = NULL;
    return n;
}


// deallocazione
// Esercizio: provate a farla ricorsiva
void l_free(list_t * l) {
    while( l ) { // l!= NULL
        list_t* aux = l;
        l = l->next;
        free(aux);
    }
}

// stampare
void l_print(list_t* n) {
    printf("<");
    while( n!= NULL ) {
        printf(" %d", n->data);
        n = n->next;
    }

    printf(" >\n");
}

// push_front_v1
list_t* l_push_front_v1(list_t *n, int val) {
    list_t* new_n = l_create_node(val);
    new_n->next = n;
    return new_n;
}

// append
list_t * l_push_back_v1(list_t *l, int val) {
    if (l==NULL) {
        return l_create_node(val);
    } else {
        list_t *old_l = l;
        while( l->next != NULL ) {
            l = l->next;
        } 
        // il next dell'ultimo nodo diventa il puntatore al nuovo nodo
        l->next = l_create_node(val);
        return old_l; // testa della vecchia lista
    }
}


// data una lista, restituire una nuova lista con soli
// gli elementi distinti (ovvero senza doppioni) (in qualunque ordine)
// {1,2, 3, 4, 3, 2, 1} => {1,2,3,4}

bool is_in (list_t * l, int x) {
    while ( l ) { // ok anche per lista vuota
        if ( l->data == x )
            return true;
        l = l->next;
    }
    return false;
}

list_t * uniq(list_t * l) {
    list_t * new_l = NULL;
    // itero la lista l
    while ( l ) {
        // se l'elemento i-esimo di l non è nella nuova lista,
        //     allora lo inserisco
        if ( !is_in(new_l, l->data) )
            // inserisco
            new_l = l_push_back_v1(new_l, l->data);
        l = l->next;
    }
    return new_l;
}

int main() {

    // nuova = l_push_front_v1(l, i);
    // free(nuova);
    // free(l);
    // // desiderata:
    // l_push_front(l, i); // l è modificata dentro push_front
    //                     // push front non ritorna nulla
    // free(l);


    list_t* l = NULL; // empty

    for (int i=1; i<=4; i++)
        l = l_push_back_v1(l, i);
    for (int i=3; i>=1; i--)
        l = l_push_back_v1(l, i);

    l_print(l);

    list_t * uni = uniq(l);
    l_print(uni);

    l_free(l);
    l_free(uni);

    return 0;
}

