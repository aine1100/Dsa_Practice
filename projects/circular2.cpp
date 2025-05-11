#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int newdata){
        data=newdata;
        next=nullptr;
    }
};

class Queue{
    public:
    Node *front,*rear;
    Queue(){
        front=rear=nullptr;
    }
};

void enQueue(Queue *q,int val){
    struct Node *newNode=new Node(val);
    if(q->front==nullptr){
        q->front=newNode;
    }else{
        q->rear->next=newNode;
    }
    q->rear=newNode;
    q->rear->next=q->front;

}

int deQueue(Queue *q){
    if(q->front ==q->rear){
        cout << "Queue is Empty";

    }
    int value;
    if(q->front==q->rear){
        value=q->front->data;
        delete(q->front);
        q->front=nullptr;
        q->rear=nullptr;
    }else{
        Node *temp=q->front;
        value=temp->data;
        q->front=q->front->next;
        q->rear->next=q->front;
        delete(temp);
    }
    return value;
}

int front(Queue *q){
    Node *front=q->front;
    if(front==nullptr){
        return -1;
    }
    return front->data;
}

int rear(Queue *q){
    Node *rear=q->rear;

    if(rear==nullptr){
        return -1;
    }
    return rear->data;
}

void printQueue(Queue *q){
    Node *curr=q->front;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while (curr !=q->front);
    cout <<endl;
  
}

int main(){
    Queue *q=new Queue;
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);
    enQueue(q, 20);

    cout << "Front value: " << front(q) << endl;
    cout << "Rear value: " << rear(q) << endl;

    printQueue(q);

    cout << "Deleted value = " << deQueue(q) << endl;
    cout << "Deleted value = " << deQueue(q) << endl;

    printQueue(q);

    return 0;
}