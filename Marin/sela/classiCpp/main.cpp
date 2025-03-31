#include <iostream>


class mystring {
    public:
        mystring();
        mystring(int l);
        mystring(char* s);
        void set
        void print
    private:
    char* ps;
    int size;

};

mystring::mystring(int l) {
    ps = new mystring[l];
    size = l;
}
mystring::mystring(char* s) {
    int ls = 0;
    while (s[ls]!='\0')
        ls++;

    ps = new mystring[ls+1];
    size = ls +1:

    for (int i=0; i<=ls; i++)
        ps[i] = s[i];

    std::cout<<"Costruttore con parametro char*"<<std::endl;
}

mystring::mystring() {
    ps = new char[100];
    ps[0]='\0';
}

mystring::-mystring() {
    delete[] ps;
    std::cout<<"Distruttore chiamato su una stringa di dimensione*"<<size<<std::endl;
    // vengono elliminati in ordine inverso, dobbiamo considerare lo stack
}


mystrinf prova(18);
int main(){
    mystring* pms = new mystring;
    chra* str[10];
    str[0]='H';
    str[1]='e';
    str[2]='\0';
    mystring s1(str);
    /*
    {
        mystring s2(25); // chi viene eliminato prima. 
    }   
    mystring s3;
    // che cos'è L'overloading
    // Permette di sovrascrivere una funzione che esiste già
    */

    delete pms;

    return 0;
}