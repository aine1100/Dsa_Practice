#include<iostream>

using namespace std;

int queue[100],front=-1,rear=-1,size=0;

void enqueue(int val){
    if(rear==100-1){
        cout << "Queue Full"<<endl;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=val;
        size++;
    }

}

void dequeue(){
    if(front==-1){
        cout <<"The Queue is empty"<<endl;
    }
    cout << "Thre removed element is "<<queue[front]<<endl;
    front++;
    size--;
}

void display(){
    if(front==-1){
        cout << "Queue is empty"<<endl;
    }
    for(int i=front;i<=rear;i++){
        cout << "Element at index "<<i<<"="<<queue[i]<<endl;
    }
}
int peek(){
    if(front==-1){
        cout << "Queue is empty"<<endl;
        return 0;
    }
    return queue[front];
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
   
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}