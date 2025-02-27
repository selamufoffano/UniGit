#include <iostream>
int swap(int a, int b){
    int x;
    x=a;
    a=b;
    b=x;
}

int main(){
    int p{3}, q{8};
    swap(p, q); // posso fare swap(p+5, q); ??
                // non posso fare perchè la funzione si aspetta un oggetto dal nome p e in quanto non esiste p+5. 
                // Il 5 non è un oggetto 
    std::cout << p << " " << q << std::endl; 
    // com farei questo codice in C?
    return 0;
}