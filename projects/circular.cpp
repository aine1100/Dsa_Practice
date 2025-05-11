#include<iostream>
using namespace std;

class MyQueue{
    private:
    int *arr;
    int front,size;
    int capacity;
    public:
    MyQueue(int c){
        arr=new int[c];
        capacity=c;
        size=0;
        front=0;
    }
    int getFront(){
        if(size==0){
            cout << "The Queue is Empty";
        }
        return arr[front];
    }
    int getRear(){
        if(size==0){
            cout<<"Queue is Empty";
        }
        int rear=(front+size-1)%capacity;
        return arr[rear];
    }
    void enqueue(int x){
        if(size==capacity){
            cout<<"It is Full";
            return;
        }
        int rear=(front+size)%capacity;
        arr[rear]=x;
        size++;
    }
    int dequeue(){
        if(size==0){
            cout <<"Queue is Empty";
        }
        int res=arr[front];
        front=(front+1)%capacity;
        size--;
        return res;
    }
};
int main() {
    MyQueue q(4);
    q.enqueue(10);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(20);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(50);
    cout << q.getFront() << " " << q.getRear() << endl;
    return 0;
}
