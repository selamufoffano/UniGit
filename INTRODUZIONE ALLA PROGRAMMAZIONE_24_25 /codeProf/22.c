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



void l_push_front(list_t **n, int val) {
    list_t* new_n = l_create_node(val);
    new_n->next = *n; // NULL
    *n = new_n;
}

// append
void l_push_back(list_t **l, int val) {
    if ( *l == NULL ) {
        *l = l_create_node(val);
    } else {
        list_t *ll = *l;
        while( ll->next != NULL ) 
            ll = ll->next; 
        // il next dell'ultimo nodo diventa il puntatore al nuovo nodo
        ll->next = l_create_node(val);
    }
}



int somma_rec (list_t* l) {
    // caso base
    if ( l==NULL )
        return 0;

    // passo ricorsivo
    return l->data + somma_rec (l->next);
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


// implementazione ricorsiva della uniq
list_t* uniq_rec (const list_t *l) {
    // caso base
    if (l==NULL)
        return NULL;

    // passo ricorsivo
    // scomposizione in sotto-problemi
    // 1) il primo elemento ( l )
    // 2) la sottolista dal secondo in poi ( l->next )

    list_t* new_l = uniq_rec ( l->next );

    if ( !is_in(new_l, l->data) ) {
        list_t *n = l_create_node(l->data);
        n->next = new_l;
        new_l = n;
    }
    return new_l;
}

// remove_all ricorsiva: rimuove tutti gli elementi
//     uguali a un intero dato

void l_remove_all(list_t **l, int x) {
    // caso base
    if (*l==NULL)
        return;

    // scomposizione:
    // oracolo dal secondo in poi
    l_remove_all( &( (*l)->next ) , x ) ;

    // il primo di l è == x ?
    if ( (*l)->data == x) { // se si elimino
        list_t *tmp = *l;
        *l = (*l)->next; //secondo elemento della lista;
        free(tmp);
    }
}

// per casa: reverse list

void l_vererse () {
    
}

int main() {

    list_t* l = NULL; // empty

    for (int i=1; i<=4; i++)
        l_push_back( &l, i);
    for (int i=1; i<=4; i++)
        l_push_front( &l, i );

    l_print(l);

    l_remove_all(&l, 4);
    l_print(l);



    list_t * uni = uniq_rec(l);
    l_print(uni);

    l_free(l);
    l_free(uni);

    return 0;
}