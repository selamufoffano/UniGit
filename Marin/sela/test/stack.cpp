#include <iostream>
using namespace std;

class stack{
    public:
    stack();
    stack(const stack e);
    -stack();
    void push(int e);
    void pop();
    int& top();
    const int& top() const;
    bool is_valid();
    private:
    struct cell {
        int info;
        cell* next;
    };
    cell* head;
}

class queue{
    public:

    private:
    

}

std::struct(){const }
//copiare constract la lista dentro

//copia liste semplice scorrendo
int main(){
    for(){

    }
    return 0;
}