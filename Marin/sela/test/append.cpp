#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> appendArray(vector<int>* ele[]) {
    std::vector<int> newArray;
    
    for (int i = 0; i < 10; i++) {
        if (ele[i] != nullptr) {  // Controllo per evitare null pointer
            newArray.insert(newArray.end(), ele[i]->begin(), ele[i]->end());
        }
    }
    
    return newArray;
}



int main(){
    vector<int> vArray = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> v10;
    for(int i=0; i<vArray.size(); i++){
        v10.push_back(vArray.at(i));
    }
    std::vector<int>* array[10] = {&v10};

    std::vector<int> copiedArray = appendArray(array);

    // Stampa del nuovo array
    for (int num : copiedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
