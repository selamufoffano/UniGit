
/**
#include <iostream>

int main() {
    std::cout << "Hello World!";
    return 0;
}
**/

#include <iostream>
int main(){
    int a;
    std::cin>>a; // leggo la variabile a. 
                 // scanf("%d", &a); 
    int s;
    std::cin>>s; // scanf("%s", &str[0]); 
    std::cout<<"hello world! %d, %d", a<<std::endl;
    // std è un nameSpace della libreria standardout. 
    // std è solo un nameSpace. Diversi team che lavorano allo stesso progetto 
    // potrebbero utilizzare un medesimo nome per una funziona. con i nameSpace evito i nomi sovraposti

    // Cos'è un USING NAMESPCAE? 
    return 0;
}
