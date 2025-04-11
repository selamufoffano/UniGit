#include <iostream>
#include <string>
using namespace std;

int somma(int x, int y){
    return x+y;
}
/*int somma(int x, int y){
    return x+y;
}*/ // mi restituisce errore
int somma(int x, int y, int k){
    return x+y+k;
}
int main(){
    int result = somma(10, 20);
    result = somma(10, 20, 30);
    std::cout <<result <<std::endl;
    return 0;
}

/* 
In questo esempio abbiamo due funzioni con lo stesso 
Il compilatore non guarda il nome ma la firma, se due funzioni con lo stesso 
hanno la stessa firma (i parametri)
*/
