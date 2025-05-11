#include<iostream>
using namespace std;
//implementing queue using array
//using struct

// struct Queue{
//     int front,n,rear;
//     int *queue;
//     Queue(int c){
//         front=rear=-1;
//         n=c;
//         queue=new int[n];
//     }
// };
//using generic datatypes
// template<typename T>
// struct queue{
//     int front,rear,n;
//     T* queue;
//     queue(int c){
//         front=rear=-1;
//         n=c;
//         queue=new T;
//     }
    

// }
// void enqueuee(T val){
    
// }
//for other things use the same logic nothing changes on the recent logic that we recently used before

// struct queue2{
//     int front,rear,capacity;
//     int *arr;
//     queue2(int c){
//         front=rear=0;
//         capacity=c;
//         arr=new int;
//     }
    
//     void enqueue2(int data){
//         if(capacity==rear){
//             cout<<"Queue overflow";
            
//         }
//         arr[rear]=data;
//         rear++;
//         return;
//     }
//     int front2(){
//         return arr[front];
//     }
    
//     void dequeue2(){
//         if(front==rear){
//             cout<<"Empty quee";
//         }
//         for(int i=front;i<=rear;i++){
//             arr[i]=arr[i+1];
//         }
//         rear--;
//         capacity--;
    
//     }
//     void display2(){
//         if(front==queue){
//             cout<<"Queue underflow";
            
//         }
//         for(int i=front;i<=rear;i++){
//             cout<<arr[i];
//     }
    
// }

// class Queue{
//     T *arr;
//     int nextIndex;
//     int firstIndex;
//     int size;
//     int capacity;
//     public:
//     Queue(){
//     capacity=5;
//     arr=new T(capacity);
//     nextIndex=0;
//     firstIndex=-1;
//     size=0;
//     }
//     Queue(int cap){
//         capacity=cap;
//         arr=new T(capacity);
//         nextIndex=0;
//         firstIndex=1;
//         size=0;
        
//     }
//     void enqueue(T ele){
//         if(size==capacity){
//             cout<<"Queue is full"<<endl;
//             return;
//         }
//         arr[nextIndex]=ele;
//         nextIndex=(nextIndex+1)%capacity;
//         if(firstIndex==-1){
//             firstIndex=0;
//         }
//         size++;
//     }
//     int getSize(){
//         return size;
//     }
//     bool isEmpty(){
//         return size==0;
//     }
//     T front(){
//         if(isEmpty()){
//             cout<<"Queue is Empty"<<endl;
//             return 0;
//         }
//         return arr[firstIndex];
//     }
//     void dequeue(){
//         if(isEmpty()){
//             cout<<"The Queue is empty"<<endl;
//             return ;
//         }
//         firstIndex=(firstIndex+1)%capacity;
//         size--;
//     }
// }
template <typename T>

class Queue{
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    Queue(){
    capacity=5;
    arr=new T[capacity];
    nextIndex=0;
    firstIndex=-1;
    size=0;
    }
    Queue(int cap){
        capacity=cap;
        arr=new T(capacity);
        nextIndex=0;
        firstIndex=1;
        size=0;
        
    }
    void enqueue(T ele){
        if(size==capacity){
            T *newArr=new T[2*capacity];
            int j=0;
            
            for(int i=front;i<capacity;i++){
                newArr[j]=arr[i];
                j++;
            }
            front=0;
            rear=capacity;
            capacity=capacity*2;
            delete []arr;
            arr=newArr;
        }
        arr[rear]=ele;
        rear=rear+1;
        if(front==-1){
            front=0;
        }
        size++;
        arr[nextIndex]=ele;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1){
            firstIndex=0;
        }
        size++;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return arr[firstIndex];
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"The Queue is empty"<<endl;
            return ;
        }
        firstIndex=(firstIndex+1)%capacity;
        size--;
    }
};


int queue[100];
int n=100,rear=-1,front=-1;

void enqueue(int val){
    if(rear==n-1){
        cout<<"Queue overflow";
    }
    if(front==-1){
        front=0;
       
    }
    rear++;
    queue[rear]=val;
}

void dequeue(){
    if(front==-1 ||front >rear){
        cout<<"Queue underflow";
        return;
    }
    cout<<"Element Deleted from queue"<<queue[front]<<endl;;
    front++;
}

void display(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"elements are:";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<",";
        }
    }
}

void frontdisplay(){
    if(front==-1){
        cout<<"Queue underflow"<<endl;
    }
    cout<<"Element at the front are:"<<queue[front]<<endl;
}
//dequeue with shifting

void dequeueshift() {
    if (front == -1 || front > rear) { // Proper underflow check
        cout << "Queue underflow" << endl;
        return;
    }
    
    // Display the element to be deleted
    cout << "The element to delete is: " << queue[front] << endl;

    // Shift all elements one position to the left
    for (int i = front; i < rear; i++) {
        queue[i] = queue[i + 1];
    }

    rear--; 
    n--;
    // Reduce the queue size by one

    // Check if the queue is now empty
    // if (rear < front) {
    //     front = rear = -1; // Reset both pointers if the queue is empty
    // }
};

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    frontdisplay();
    dequeueshift();
    display();
}