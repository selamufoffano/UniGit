#include <iostream>
#include <cassert>
int climb(int n){
    assert(n>= 0);
    if(n==0){
        return 0;
    } else {
        return 1 + climb(n-1);
    }
}

int power(int x, int y){
    assert(y >=0);
    if(y==0) return 1;
    return x * power(x, y-1);
}
bool palindromo(int i, int j, std::string const& s){
    /*
    abba
    */
    if(i>=j) return true;
    if(s[i] != s[j]) return false;
    return palindromo(i+1, j-1, s);
}
uint64_t factor(const uint64_t n){
    if (n==0) return 1;
    return n* factor(n-1);
}

int fibo(int n){

}

int main(){
    //climb(7);
    //power(10, 2);
    std:: string const& s = "ABBA";
    //palindromo(0, 0, s);
    factor(int n);
    return 0;
}