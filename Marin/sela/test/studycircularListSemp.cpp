#include <iostream>
using namespace std;

class CircularList {
    public:
        CircularList();
        ~CircularList();
        void append(int val);
        void prepend(int val);
        void print_forward(int count);
    private:
        struct Node {
            int info;
            Node* next;
        };
    Node* head;
};

CircularList::CircularList() {
    head = nullptr;
}

void CircularList::append(int val) {
    Node* newNode = new Node{val, nullptr};
    if (head == nullptr) {
        head = newNode;
        newNode->next = head; 
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // mantenere la circolarità
    }
}
void CircularList::prepend(int val){
    Node* newNode = new Node{val, nullptr};
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void CircularList::print_forward(int count) {
    if (head == nullptr) return;
    Node* temp = head;
    for (int i = 0; i < count; ++i) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}
CircularList::~CircularList() {
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

int main() {
    CircularList list;
    int num;
    cout << "Insert 5 numbers: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        list.prepend(num);
        //list.append(num);
    }

    cout << "List forward: ";
    list.print_forward(5);

    return 0;
}
