#include <iostream>

using namespace std;

class listCirc{
    public:
        listCirc(); // costruttore di dafult
        listCirc(const listCirc& l);
        -listCirc();
        void add(int l);
        void remove(int l);
        void print() const;
        int& getcur();
        void moveNext();
    private:
        struct cell{
            int info;
            cell* next;
        };
        cell* cur;
};

listCirc::listCirc(){
    cur = nullptr;
}

void listCirc::add(int l){
    cell* pc = new cell;
    if(cur!=nullptr){
        pc->next = cur -> next;
        cur->next = pc;
        pc->info = l;
    } else {
        pc->next = pc;
        pc->info=l;
        cur=pc;
    }
}


void listCirc:: print() const{
    cell* pc = cur;
    if(pc!=nullptr){
        do {
            cout<<pc->info;
            pc=pc->next;
        } while(pc!=cur);
    }
}

//ricorsivo
void listCirc::print_recur(cell* pc, cell& fine){

}

void listCirc::remove(int l){
    cell* pc = cur;
    if(cur){
        do {
            if(pc->next->info == l){
                found = true;
                cell* temp = pc->next;
                if(temp == cur){
                    if(cur==cur) 
                    else // da finire chiedere a seba
                }
                pc->next = temp->next;
                delte temp;
            } else {
                pc = pc->next;
            }
        } while(pc != cur && !found);
    }
}

listCirc::listCir(const listCir l){
    cur = nullptr;
    cell* pc = l.cur;
    if(pc!=nullptr){
        do {
            cout<<pc->info;
            add(pc->info);
            pc=pc->next;
            cur = cur->next;
        } while(pc!=l.cur);
        cur = cur->next;
    }

}
// controllare se c'è un elemento nella lista circolare
// e provare altri esercizi
// lunghezza 
// tutti gli elementi pari o dispari
// 
int main(){
    return 0;
}

// Problema x casa liste con cappio
/*
data una lista partendo da un puntatore  ptr alla prima cella determianre se è lineare o un capio
1 = lineare
2 = ha un cappio
*/