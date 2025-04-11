#include <iostream>

using namespace std;
struct Node{ // liste doppiamente concatenate
    int info;
    Node* next;
    Node* prev;
};
void print_forward(Node* cur);
void print_reverse(Node* cur, Node* tail);

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int num = 0;
    for(int i=0; i<10; i++){
        cin >> num;
        Node* newNode = new Node{num, nullptr, nullptr};
        if(head == nullptr) head = tail = newNode;
        else {
            //prepend
            /*
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
            */
            // prepend 
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    print_forward(head);
    print_reverse(head, tail);
    return 0;
}

void print_forward(Node* cur){
    cout << "Lista (forward): ";
    Node* curr = cur;
    while (curr != nullptr) {
        cout << curr->info << " ";
        curr = curr->next;
    }
    cout << endl;
}

void print_reverse(Node* cur, Node* tail){
    cout << "Liste revese: ";
    Node* curr = cur;
    curr = tail;
    while (curr != nullptr) {
        cout << curr ->info << " ";
        curr = curr ->prev;
    }
    cout << endl;
}