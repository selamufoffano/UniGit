#include <iostream>
int main(){
    int x; // la varibaile x non è stata inizializzata, 
           // non è detto che assuma come valore di default = 0
    int y = x*7;
    std::cout << y << std::endl;
    return 0;
}