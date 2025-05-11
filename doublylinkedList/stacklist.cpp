// #include<iostream>
// using namespace std;
// template<typename T>

// class Node{
//     public:
//     T data;
//     Node<T> *next;
//     Node (T d){
//         this->data=d;
//         next=NULL;
//     }
// };
// template<typename T>
// class Stack{
//     Node<T> *head;
//     int size;
//     public:
//     Stack(){
//         head=NULL;
//         size=0;
        
//     }
//     int getSize(){
//         return size;
//     }
//     bool isEmpty(){
//         return size==0;
//     }
//     void push(T ele){
//         Node<T> *n=new Node<T>(ele);
//         n->next=head;
//         head=n;
//         size++;
//     }
//     void isPop(){
//         if(isEmpty()){
//             cout<<"Stack Underflow"<<endl;
//             return;
//         }
//         Node<T> *temp=head;
//         head=head->next;
//         temp->next=NULL;
//         delete temp;
//         size --;
//     }
//     T Top(){
//         if(isEmpty()){
//             cout<<"Stack Underflow"<<endl;
//         }
//         return head->data;
//     }
//     void display(){
//         if(isEmpty()){
//             cout<<"Stack Underflow"<<endl;
//         }
//         Node<T> *temp=head;
//         cout<<"The elements are:"<<endl;
//         while(temp!=nullptr){
//             cout<<temp->data<<endl;
//             temp=temp->next;
//         }
        
//     }
// };

// int main(){
//     Stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.display();
//     cout<<s.Top()<<endl;
//     s.isPop();
//     s.isPop();
//     s.display();
// }

//implementation without generics

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        this->data=d;
        next=NULL;
    }
};

class Stack{
    
    int size;
    Node *head;
    public:
    Stack(){
        head=NULL;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(int ele){
        Node *newNode=new Node(ele);
        newNode->next=head;
        head=newNode;
        size++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow";
        }
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        size --;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack Underflow";
        }
        return head->data;
    }
    void display(){
        if(isEmpty()){
            cout<<"The Stack is Empty"<<endl;
            
        }
        Node *temp=head;
        cout<<"The elements are:"<<endl;
        while(temp!=nullptr){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        
    }
    
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.display();
}

