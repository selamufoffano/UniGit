#include <iostream>
using namespace std;

struct cell(){
    int info;
    cell* next;
};
typedef cell* pcell;

class list(){
    public:
        list();
        listint(const listint& l);
        - list();
        void pre(int m);
        void (int n);
        int& at(int n);
        print()
    private:
    pcell head;
}

int main(){

}

list int::list(){

}


list::listint (const listint& l){
    pcell pc = l.head();
    head == nullptr;
    pcell tail = head;
    // this -> head = ncell (sintatticamente so che è una variabile globale)
    for (; pc!=nullptr; pc=pc->next){
        if(head == nullptr){
            head = n;
        } else {
            tail -> next = n;
        }
        tail = n;
    }
}

// append
void list::append (const listint& l){
    pcell nuova = new cell{n, nullptr};
    if(head == nullptr){
        head = nuova;
    } else {
        pcell pc;
        for(pc = ){};
    }
}

//prepend