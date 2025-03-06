#include <iostream>

int main(){

    int s;
    std::vector<int> myv;
    std::cout << s;
    return 0;
}

void binary(const std::vector<int>& v, int e, int da, int a){
    int m = (da + a)/2;
    if(v.at(m) == e){
        return true;
    }else{
        if(v.at(m) > e){
            return binary();
        }
        else{
            binary();
        }
    } else{
        return false;
    }
}