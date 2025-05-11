#include<iostream>
using namespace std;

struct Stack{
    int *arr;
    int capacity;
    int nextIndex;

    Stack(int cap){
        capacity=cap;
        arr=new int[capacity];
        nextIndex=0;
    
    }
    void push(int val){
        if(isFull()){
            cout << "Stack Overflow";
        }else{
            arr[nextIndex]=val;
            nextIndex++;
        }
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow";
        }else{
           cout<<"The Removed Element is:"<<peek()<<endl;
           nextIndex--;
        }

    }
    bool isEmpty(){
        return nextIndex==0;
        // if(nextIndex==0){
        //     return true;
        // }else{
        //     return false;
        // }
    }
    bool isFull(){
        return nextIndex==capacity;
        
        // if(nextIndex==capacity){
        //     return true;
        // }else{
        //     return false;
        // }
    }
    int peek(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[nextIndex-1];
        }
    }
    void display(){
        while(!isEmpty()){
            cout<<peek()<<" "<<endl;
            pop();
        }
    }
    void print(){
        for(int i=nextIndex-1;i>0;i--){
            cout<<arr[i]<<" "<<endl;
        }
    }
};
int main(){
    Stack *mystack=new Stack(5);
    cout <<"Adding Elements in the Stack"<<endl;
    mystack->push(10);
    mystack->push(20);
    mystack->push(30);
    mystack->push(40);
    mystack->push(50);
    mystack->push(60);
    mystack->push(70);
    cout<<"The element at the top is"<<mystack->peek()<<endl;
    mystack->pop();
    mystack->pop();
    mystack->print();
    return 0;
}