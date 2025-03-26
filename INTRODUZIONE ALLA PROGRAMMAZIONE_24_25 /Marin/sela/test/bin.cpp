/*
#include <iostream>
int main(){
    short* P;
    short int Val = 5;
          
    P = &Val;    // P punta a Val (cioe` Val e *P
                 // sono lo stesso oggetto);
    std::cout << "Ora P punta a Val:" << std::endl;
    std::cout << "*P = " << *P << std::endl;
    std::cout << "Val = " << Val << std::endl;
          
    *P -= 10;    // Modifica l'oggetto puntato da P
    std::cout << "Val e` stata modificata tramite P:" << std::endl;
    std::cout << "*P = " << *P << std::endl;
    std::cout << "Val = " << Val << std::endl;
          
    Val = 30;
    std::cout << "La modifica su Val si riflette su *P:" << std::endl;
    std::cout << "*P = " << *P << std::endl;
    std::cout << "Val = " << Val << std::endl;
    
    return 0;
}
*/

#include <iostream>
using namespace std;

// Una lista e` composta da tante celle linkate
// tra di loro; ogni cella contiene un valore
// e un puntatore alla cella successiva.

struct TCell {
  float AFloat;  // per memorizzare un valore
  TCell* Next;  // puntatore alla cella successiva
};

// La lista viene realizzata tramite questa
// struttura contenente il numero corrente di celle
// della lista e il puntatore alla prima cella

struct TList{
  unsigned Size;  // Dimensione lista
  TCell* First;   // Puntatore al primo elemento
};

int main(int, char* []) {
  TList List;        // Dichiara una lista
  List.Size = 0;     // inizialmente vuota
  int FloatToRead;
  cout << "Quanti valori vuoi immettere? " ;
  cin >> FloatToRead;
  cout << endl;
    
  // questo ciclo richiede valori reali 
  // e li memorizza nella lista 

  for(int i=0; i < FloatToRead; ++i) {
    TCell* Temp = List.First;
    cout << "Creazione di una nuova cella..." << endl;
    List.First = new TCell;    // new vuole il tipo di
                               // variabile da creare
    cout << "Immettere un valore reale " ;
    
    // cin legge l'input da tastiera e l'operatore di
    // estrazione >> lo memorizza nella variabile.
    cin >> List.First -> AFloat;
    cout << endl;
    List.First -> Next = Temp; // aggiunge la cella in
                               // testa alla lista
    ++List.Size;       // incrementa la
                       // dimensione della lista
  }
    
  // il seguente ciclo calcola la somma
  // dei valori contenuti nella lista;
  // via via che recupera i valori,
  // distrugge le relative celle
  float Total = 0.0;
  for(int j=0; j < List.Size; ++j) {
    Total += List.First -> AFloat;

    // estrae la cella in testa alla lista...
    TCell* Temp = List.First;
    List.First = List.First -> Next;

    // e quindi la distrugge
    cout << "Distruzione della cella estratta..." << endl;
    delete Temp;
  }
  cout << "Totale = " << Total << endl;
  return 0;
}

