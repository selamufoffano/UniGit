#include <iostream>

int main(){
    buble();
}
void buble(vector<int>& v){
    for(int soglia=0;soglia<v.size(); soglia++){
        // prenod l'elemento più piccolo
        // del range [soglia, size-1] e devo mettere
        // in posizione soglia
        for(int i=size-1;i>soglia.size(); i--){ 
            // come faccio a capire se soglia deve essere ">" 
            // e non ">="
            if(v[i]<v[i-1]){
                swap(v[i], v[i-1]);
            }
        }
    }
}

void swap(int a, int b){
    int c = a;
    a = b;
    b = c;
}