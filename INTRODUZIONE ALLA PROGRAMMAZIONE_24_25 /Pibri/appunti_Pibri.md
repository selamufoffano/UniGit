# 14_02_25
## g++ - infludes
- .hpp
- .object file

# 19_02_25

# 21_02_25

# Asserts 
```c++
#include <cassert>
int main(){
    int power(int x, int y){
        assert(y >= 0); // attraverso il comando assert possiamo 
                        // porre una pre-condizione al nostro codice, 
                        // è neccessario #include <cassert>
        int pw=1;
        for(int i; i<y; i++){
            pw*=x;
        }
        return pw;
    }   
    // possiamo porre una pre-condizione con gli asserts

}
```

#### valgrind
// 

#### Uninitialized memory
```c++
// compiando il codice con valgrind
#include <iostream>
int main(){
    int x; // la varibaile x non è stata inizializzata, 
           // non è detto che assuma come valore di default = 0
    int y = x*7;
    std::cout << y << std::endl;
    return 0;
}
```