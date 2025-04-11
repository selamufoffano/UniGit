#include <iostream>
using namespace std;

class CircularList {
    public:
        CircularList() {
            head = nullptr;
        }

        void ins_tail(int val) {
            Node* newNode = new Node{val, nullptr, nullptr};

            if (head == nullptr) {
                // Primo nodo: punta a sé stesso (lista circolare)
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node* tail = head->prev;

                newNode->next = head;
                newNode->prev = tail;
                tail->next = newNode;
                head->prev = newNode;
            }
        }

        void print_forward() {
            if (head == nullptr) return;

            Node* temp = head;
            do {
                cout << temp->info << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }

        void print_reverse() {
            if (head == nullptr) return;

            Node* temp = head->prev; // tail
            Node* start = temp;
            do {
                cout << temp->info << " ";
                temp = temp->prev;
            } while (temp != start);
            cout << endl;
        }
        ~CircularList() {
            if (head == nullptr) return;

            Node* temp = head->next;
            while (temp != head) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            delete head;
            head = nullptr;
        }

    private:
        struct Node {
            int info;
            Node* next;
            Node* prev;
        };
    Node* head;
};



int main() {
    CircularList list;
    int num;

    cout << "Inserisci 5 numeri: ";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        list.ins_tail(num);
    }

    cout << "Stampa in avanti: ";
    list.print_forward();

    cout << "Stampa all'indietro: ";
    list.print_reverse();

    return 0;
}
