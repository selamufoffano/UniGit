#include <iostream>
using namespace std;

int main(){
    int num[n] {1,2, 3,4,7,10};
    for(int i=0; i<num; i++){
        cout<<num[i]<<endl;
    }
    int numSearch = 3;
    int indexLeft = 0;
    int indexRight = num -1;
    int indexLooking;
    bool trovato = false;
    do {
        indexLooking = (indexLeft + indexRight)/2;
        if(num[indexLooking]==numSearch){
            trovato = true;

        } else {
            if(num[indexLooking] > numSearch) {
                indexRight = indexLooking;
            } else {
                indexLeft = indexLooking;
            }
        }
    } while(!trovato && indexLeft <= indexRight);
    return 0;
}