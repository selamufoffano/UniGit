#include <iostream>
using namespace std;
struct lista {
    string nome = "";
    string cognome = "";
    lista* next = nullptr;
};
void ins_testa(lista* &first, lista* nuovo){
    nuovo->next = first;
    first = nuovo;
}
void stampa_lista(lista* first){
    while (first!=nullptr){
      cout << "Nome:" << first-> nome << ", Cognome: " << first -> cognome << endl;
      first = first -> next;
    }
  }
   
void distruggi_lista(lista* &first){
    while (first!=nullptr){
        lista *temp = first;
        first = first -> next;

        delete temp;
    }
}

int main(){
    lista* first = nullptr;
    lista* nuovo = nullptr;
    int count = 0;
    cout << "Insert Size of list: ";
    cin >> count;
    for(int i=0; i<count; i++){
        nuovo = new lista;
        cout << "Insert Name: ";
        cin >> nuovo->nome;
        cout << "Cognome";
        cin >> nuovo->cognome;
        ins_testa(first, nuovo);
    }
    stampa_lista(first);
    distruggi_lista(first);
    return 0;
}