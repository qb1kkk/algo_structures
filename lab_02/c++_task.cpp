//1 пример
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    
    return 0;
}

//2 пример
#include <iostream>
using namespace std;

class List {
public:
    struct Node {
        int data;
        Node* next;
    };
    
    Node* head = nullptr;
    
    void add(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }
};

int main() {
    List list;
    list.add(3);
    list.add(2);
    list.add(1);
    
    List::Node* current = list.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    
    return 0;
}
