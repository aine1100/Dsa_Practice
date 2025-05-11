#include<iostream>
using namespace std;
int n=5;
int queue[5],front=-1,rear=-1,siz=0;
bool isEmpty(){
    return siz == 0;
}
bool isFull(){
    return siz == n;
}
void enqueue(int val){
    if(isFull()){
        cout<<"Queue Full"<<endl;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=val;
        siz++;
    }
}
void dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    cout<<"The removed element is"<<queue[front]<<endl;
    front++;
    siz--;
}
int count(){
    return siz;
}
void display(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
    }
    for(int i=front;i<=rear;i++){
        cout<<"Element at i="<<i<<" "<<queue[i]<<endl;
    }
}
int peek(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    return queue[front];
}
int main(){
    cout<<peek()<<endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    cout<<count()<<endl;
    enqueue(60);
    display();
    dequeue();
    dequeue();
    display();
    cout<<peek()<<endl;
    return 0;
}





















