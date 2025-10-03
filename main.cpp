#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};
// more function prototypes made
void addNodeToFront(Node*& head, float val);
void addNodeToTail(Node*& head, float val);
void insertNode(Node*& head, float val, int position);
void deleteNode(Node*& head, int position);
void deleteList(Node*& head);
void output(Node * hd);

int main() {
    Node *head = nullptr;
    int entry;

    cout <<"--- building list with addNodeToFront---"<<endl;
    for (int i = 0; i < SIZE; i++) {
        addNodeToFront(head, rand() % 100);
    }
    output(head);
    

    // deleting a node
    cout <<"--- Deleting a node---"<<endl;
    cout << "Which node to delete? ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // inserting a node
    cout <<"--- Inserting a node---"<<endl;
    cout << "Which node to insert 10000? ";
    cin >> entry;
    insertNode(head,10000 ,entry);
    output(head);
    // inserting to tail
    cout <<"--- Adding 999 to tail---"<<endl;
    addNodeToTail(head,999);
    output(head);

    // deleting the linked list
    cout <<"--- Deleting the entire list---"<<endl;
    deleteList(head);
    output(head);



    
    
    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
void addNodeToFront(Node*& head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void addNodeToTail(Node*& head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node*& head, int position) {
    if (!head || position < 1) { 
        return;
    }

    Node* current = head;
    if (position == 1) {
        head = current->next; 
        delete current;       
        return;
    }

    
    Node* prev = nullptr;
    for (int i = 1; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position is out of bounds." << endl;
        return;
    }
    
   
    prev->next = current->next;
    delete current;
}


void insertNode(Node*& head, float val, int position) {
    if (position < 1) { 
        return;
    }
    
    Node* prev = head;
    for (int i = 1; i < position && prev != nullptr; i++) {
        prev = prev->next;
    }


    if (prev != nullptr) {
        Node *newNode = new Node;
        newNode->value = val;
        newNode->next = prev->next;
        prev->next = newNode;
    } else {
        cout << "Position is out of bounds." << endl;
    }
}

void deleteList(Node*& head) {
    Node* current = head;
    Node* nextNode = nullptr;
    
    while (current != nullptr) {
        nextNode = current->next; 
        delete current;           
        current = nextNode;       
    }
    head = nullptr;
}