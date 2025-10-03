#include <iostream>
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

    
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
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