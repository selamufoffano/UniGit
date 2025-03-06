#include <iostream>

int main(){
    anode(5, 1, 3, 2);
    return 0;
}


void anode(int dis, int from, int to, int sup){
    
    if(dis > 1){
        anode(dis-1, from, supp, to);
        cout<< from << "->" << to << endl;
        anode(dis-1, supp, to, from);
    }else{
        cout<< from << "->" << to << endl;
    }
}