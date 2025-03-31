/*
Link: https://www.youtube.com/watch?v=C93nZMZx2Is
*/
#include <iostream>
#include <string>
#include <vector>
//#include "main.cpp"
using namespace std;

class Persona{
    public:
        string nome;
        string cognome;
        int età;
        void presentaV2(){
            cout << "Nome: " << nome << " Cognome: " << cognome << " Età: " << età << endl;
        }
        void presentaV3(string nome){
            cout << "Nome: " << nome << " Cognome: " << cognome << " Età: " << età << endl;
        }
        void presentaV4(string nome){
            cout << "Nome: " << this->nome << " Cognome: " << cognome << " Età: " << età << endl;
        }
    //private:
    //protected:
};
void presenta(string nome, string cognome, int età){
    cout << "Nome: " << nome << " Cognome: " << cognome << " Età: " << età << endl;
}

int main(){

    Persona p1;
    p1.nome = "Luca";
    p1.cognome = "Rossi";
    p1.età = 25;
    //cout << "Nome: " << p1.nome << " Cognome: " << p1.cognome << " Età: " << p1.età << endl;
    presenta(p1.nome, p1.cognome, p1.età);
    p1.presentaV2();
    p1.presentaV3("Override Luca");
    p1.presentaV4("Override Luca (This)");
    return 0;
}