#include<iostream>

struct Cell{
  int info;
  Cell* next;
};

typedef Cell* List;


void append(List& l, int elem) {
  if (l==nullptr) {
    l = new Cell{elem, nullptr};
  }
  else 
    append(l->next, elem);
}


void readlist(List& l) {
  int q, e;

  std::cin>>q;

  while (q>0) {
    std::cin>>e;
    append(l, e);
    q--;
  }
}


bool findsum(List l, int sum, int add) {
    if (add == 0) {
        return sum == 0;
    }
    if (l == nullptr) {
        return false;
    }
    if (findsum(l->next, sum - l->info, add - 1)) {
        return true;
    }
    return findsum(l->next, sum, add);
}




bool findsumV2(List l, int sum, int add) {
    if (l == nullptr || add == 0) {return false;}
    int tempSom = 0;
    List auxLista = l;
    //int count = 0;
    while (auxLista ->next!= nullptr && add!=-1) {
        tempSom += auxLista->info;
        if (tempSom == sum) {
            return true;
        }
        auxLista = auxLista->next;
        //count++;
    }
    return findsum(l=l->next, sum, add-1);
}


bool findsumV1(List l, int sum, int add) {
    if (l == nullptr || add == 0) { return false;}
    
    int tempSom=0;
    List auxLista = l;
    for(int i=0; i<add && auxLista->next != nullptr; i++){
        tempSom += auxLista->info;
        if(tempSom == sum) {
            return true;
        } else {
        auxLista=auxLista->next;
        }
    }
    return findsum(l->next, sum, add);
}

bool findsumV0(List l, int sum, int add) {
    if (l == nullptr) { return false;
    }
    int tempSom=0;
    List auxLista = l;
    for(int i=0; i<add && auxLista->next != nullptr; i++){
        tempSom += auxLista->info;
        if(tempSom == add) {
            return true;
        }
        auxLista=auxLista->next;
    }
    return findsum(l->next, sum, add);
}

int main() {
  List l{nullptr};

  readlist(l);

  int sum;
  int add;

  std::cin>>sum;
  std::cin>>add;

  if (findsum(l, sum, add))
    std::cout<<"Somma trovata"<<std::endl;
  else
    std::cout<<"Somma non trovata"<<std::endl;

}

