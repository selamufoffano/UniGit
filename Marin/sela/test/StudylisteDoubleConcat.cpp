#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int num = 0;

    // Inserimento di 10 elementi nella lista doppiamente concatenata
    for (int i = 0; i < 10; i++) {
        cin >> num;
        Node* newNode = new Node{num, nullptr, nullptr};

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            // Append in coda
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

             // Prepend in testa
             /*
             newNode->next = head;
             head->prev = newNode;
             head = newNode;
             */
        }
    }

    // Stampa in ordine (forward)
    cout << "Lista (forward): ";
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->info << " ";
        curr = curr->next;
    }
    cout << endl;

    // Stampa in ordine inverso (reverse)
    cout << "Lista (reverse): ";
    curr = tail;
    while (curr != nullptr) {
        cout << curr->info << " ";
        curr = curr->prev;
    }
    cout << endl;

    return 0;
}
