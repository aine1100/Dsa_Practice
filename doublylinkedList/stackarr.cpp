// #include<iostream>
// using namespace std;
// #include<string>
// class Stack{
//     int *arr;
//     int nextIndex;
//     int capacity;
//     public:
//     Stack(){
//         capacity=4;
//         arr=new int[capacity];
//         nextIndex=0;
//     }
//     Stack(int cap){
//         capacity=cap;
//         arr=new int[capacity];
//         nextIndex=0;
//     }
//     int size(){
//         return nextIndex;
//     }
//     void push(int ele){
//         if(nextIndex==capacity){
//             cout<<"Stack Overflow";
//             return;
            
//         }
//         arr[nextIndex]=ele;
//         nextIndex++;
        
//     }
//     void push2(int ele){
//         if(nextIndex==capacity){
//           int *newArr=new int[capacity*2];
//           for(int i=0;i<=nextIndex;i++){
//               newArr[i]=arr[i];
//           }
//           delete []arr;
//           arr=newArr;
//           capacity=2*capacity;
            
//         }
//         arr[nextIndex]=ele;
//         nextIndex++;
        
//     }
//     void pop(){
//         if(nextIndex==0){
//             cout<<"Stack underflow";
//             return;
//         }
//         nextIndex--;
        
//     }
//     void peek(){
//         if(nextIndex==0){
//             cout<<"Stack underflow";
//         }
//         cout<< arr[nextIndex-1]<<endl;
//     }
//     void display(){
//         if(nextIndex==0){
//             cout<<"Stack Underflow";
//         }
//         cout<<"The elements are:"<<endl;
//         for(int i=nextIndex-1;i>=0;i--){
//          cout<<arr[i]<<endl;
//         }
        
//     }
    string reverse(string word){
        Stack<char> s;
        for(char ch:word){
            s.push(ch);
            
        }
        string rev="";
        while(!s.isEmpty()){
            rev+=s.top();
            s.pop();
        }
        return rev;
    }
};

// int main(){
//     Stack s(4);
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.display();
//     s.peek();
//     s.pop();
//     s.pop();
//     s.peek();
//     s.display();
//     s.push2(50);
//     s.push2(60);
//     s.push2(70);
//     s.push2(90);
//     s.push2(100);
//     s.push2(110);
//     s.display();
    
//     return 0;
// }


#include<iostream>
using namespace std;
#include<string>
template<typename T>
class Stack{
    T *arr;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        capacity=4;
        arr=new T[capacity];
        nextIndex=0;
    }
    Stack(int cap){
        capacity=cap;
        arr=new T[capacity];
        nextIndex=0;
    }
    int size(){
        return nextIndex;
    }
    void push(T ele){
        if(nextIndex==capacity){
            cout<<"Stack Overflow";
            return;
            
        }
        arr[nextIndex]=ele;
        nextIndex++;
        
    }
    void push2(T ele){
        if(nextIndex==capacity){
           T *newArr=new T[capacity*2];
           for(int i=0;i<=nextIndex;i++){
               newArr[i]=arr[i];
           }
           delete []arr;
           arr=newArr;
           capacity=2*capacity;
            
        }
        arr[nextIndex]=ele;
        nextIndex++;
        
    }
    void pop(){
        if(nextIndex==0){
            cout<<"Stack underflow";
            return;
        }
        nextIndex--;
        
    }
    void peek(){
        if(nextIndex==0){
            cout<<"Stack underflow";
        }
        cout<< arr[nextIndex-1]<<endl;
    }
    void display(){
        if(nextIndex==0){
            cout<<"Stack Underflow";
        }
        cout<<"The elements are:"<<endl;
        for(int i=nextIndex-1;i>=0;i--){
         cout<<arr[i]<<endl;
        }
        
    }
//     string reverse(string word){
//         Stack<char> s;
//         for(char ch:word){
//             s.push(ch);
            
//         }
//         string rev="";
//         while(!s.isEmpty()){
//             rev+=s.top();
//             s.pop();
//         }
//         return rev;
//     }
 };

int main(){
    Stack<char> s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.peek();
    s.pop();
    s.pop();
    s.peek();
    s.display();
    s.push2(50);
    s.push2(60);
    s.push2(70);
    s.push2(90);
    s.push2(100);
    s.push2(110);
    s.display();
    
    return 0;
}