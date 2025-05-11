#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int data;

    Node(int d) {
        this->data = d;
        this->next = nullptr; // Initialize next to NULL
        this->prev = nullptr; // Initialize prev to NULL
    }
};

void addBeginning(Node*& head, int data) {
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == nullptr) {
        newNode->next = newNode; // Point to itself (circular)
        newNode->prev = newNode; // Point to itself (circular)
        head = newNode;          // Set head to the new node
        return;
    }

    // Traverse to the last node in the list
    Node* tail = head->prev;

    // Update pointers to insert newNode at the beginning
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;

    // Update the head pointer
    head = newNode;
}
void addEnd(Node*& head,int data){
    Node *newNode=new Node(data);
    if(head==nullptr){
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        return;
    }
    Node* tail=head->prev;
    tail->next=newNode;
    newNode->prev=tail;
    newNode->next=head;
    head->prev=newNode;
   
}
void deleteFirst(Node*& head) { // Use Node*& to modify the head pointer
    if (head == nullptr) { // Check if the list is empty
        cout << "List is Empty" << endl;
        return;
    }

    // If the list has only one node
    if (head->next == head) {
        delete head;
        head = nullptr; // Set head to null since the list is now empty
        return;
    }

    // Find the last node (tail)
    Node* tail = head->prev;

    // Update the head to the next node
    Node* temp = head;
    head = head->next;

    // Update pointers to maintain circular doubly linked list
    head->prev = tail;
    tail->next = head;

    // Delete the old head
    delete temp;
}
void deleteEnd(Node*& head) { // Use Node*& to modify head
    if (head == nullptr) { // Check if the list is empty
        cout << "List is Empty" << endl;
        return;
    }

    // If the list has only one node
    if (head->next == head) {
        delete head;
        head = nullptr; // Set head to null since the list is now empty
        return;
    }

    // Find the last node (tail)
    Node* tail = head->prev;

    // Update pointers to maintain circular doubly linked list
    Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;

    // Delete the old tail
    delete tail;
}


void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Stop when we reach the head again
    cout << endl;
}

int main() {
    Node* head = nullptr;

    addBeginning(head, 60);
    addBeginning(head, 20);
    addBeginning(head, 30);
    addBeginning(head, 40);
   
    addEnd(head,50);
    deleteFirst(head);
    deleteFirst(head);
    deleteFirst(head);
    deleteEnd(head);
  

    display(head); // Expected output: 40 30 20 10
    return 0;
}
