#include <iostream>
 
using namespace std;
 
struct Calciatore {
  string cognome="";
  int goalSegnati=0;
 
  Calciatore *next = nullptr;
};
 
void ins_testa(Calciatore* &il, Calciatore* nuovo){
   nuovo->next = il;
   il = nuovo;
}
 
void ins_coda(Calciatore* &il, Calciatore* nuovo){
 
  if (il==nullptr){
    ins_testa(il, nuovo);
  }
  else //spostiamo un puntatore ausiliario sull'ultimo nodo
  {
    Calciatore *temp = il;
 
    while(temp->next != nullptr){
      temp = temp -> next;
    }
    temp -> next = nuovo;
  }
}
 
 
void stampa_lista(Calciatore* il){
  while (il!=nullptr){
    cout << il-> cognome << " = " << il -> goalSegnati << endl;
    il = il -> next;
  }
}
 
void distruggi_lista(Calciatore* &il){
  while (il!=nullptr){
    Calciatore *temp = il;
    il = il -> next;
 
    delete temp;
  }
}
 
void elimina_testa(Calciatore* &il){
  if (il!=nullptr){
    Calciatore *temp = il;
    il = il -> next;
    
    delete temp;
        
  }
}
 
void elimina_coda(Calciatore* &il, Calciatore* nuovo){
 
    if (il!=nullptr){
        if (il->next == nullptr){
            delete il;
            il=nullptr;      
        }
        else{
            Calciatore *temp = il;
        
            while(temp->next->next != nullptr){
                temp = temp -> next;
            }
            delete temp->next;
            temp->next = nullptr;    
        }
    }
}
 
 
int main(){
  Calciatore *il = nullptr;
  Calciatore *nuovo = nullptr;
  do {
 
    //creiamo un nodo
    nuovo = new Calciatore;
 
    cout << "Inserire il cognome (stop per uscire): ";
    cin >> nuovo->cognome;
 
    if (nuovo->cognome !="stop"){
      cout << "Goal segnati da questo calciatore: ";
      cin >> nuovo->goalSegnati; 
      ins_coda(il, nuovo);
    }
 
  } while (nuovo->cognome!="stop");
 
  //cout << il->cognome << " - " << il->next->cognome << endl;
  stampa_lista(il);
 
  distruggi_lista(il);
  stampa_lista(il);
  
  return 0;
}
