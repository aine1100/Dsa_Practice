#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
};

void forwardTrav(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void backwardTrav(Node *tail) {
    Node *curr = tail;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << "NULL" << endl;
}

int length(Node *head) {
    int count = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        count++;
    }
    return count;
}

Node *insertBegin(Node *head, int d) {
    Node *newNode = new Node();
    newNode->data = d;
    newNode->next = head;
    newNode->prev = NULL;

    // Update the previous pointer of the old head if it exists
    if (head != NULL) {
        head->prev = newNode;
    }

    // Return the new head of the list
    return newNode;
}
Node *insertEnd(Node *head,int d){
    Node *newNode=new Node();
    newNode->data=d;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }else{
        Node *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=newNode;
        newNode->prev=curr;
        newNode->next=NULL;
        
    }
    return head;
}
Node *deleteBegin(Node *head){
    if(head==NULL){
        cout<<"NULL"<<endl;
    }else{
        Node *temp=head;
        head=head->next;
        if(head !=NULL){
            head->prev=NULL;
        }
        delete temp;
    }
    return head;
    
}
Node *deleteEnd(Node *head){
    if(head==NULL){
        cout<<"NULL"<<endl;
    }
    if(head->next==NULL){
        delete head;
        cout<<"NULL";
    }
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->prev->next=NULL;
    delete curr;
    return head;
}

int main() {
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node *n5 = new Node();

    // Initialize nodes with data
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;
    n5->data = 50;

    // Link nodes to form a doubly linked list
    n1->prev = NULL;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = NULL;

    // Traversals and operations
    cout << "Forward traversal before insertion:" << endl;
    forwardTrav(n1);

    cout << "Backward traversal before insertion:" << endl;
    backwardTrav(n5);

    cout << "Length of the list: " << length(n1) << endl;

    // Insert a new node at the beginning
    n1 = insertBegin(n1, 60);

    // Traversals after insertion
    cout << "Forward traversal after insertion at the beginning:" << endl;
    forwardTrav(n1);
     n1 = insertEnd(n1, 70);

    // Traversals after insertion
    cout << "Forward traversal after insertion at the end:" << endl;
    forwardTrav(n1);
     n1 =deleteBegin(n1);

    // Traversals after insertion
    cout << "Forward traversal after deletion at the start:" << endl;
    forwardTrav(n1);
     n1 =deleteEnd(n1);

    // Traversals after insertion
    cout << "Forward traversal after deletion at the end:" << endl;
    forwardTrav(n1);
}
