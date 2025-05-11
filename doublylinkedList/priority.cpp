#include<iostream>
using namespace std;

struct Student{
    int code;
    string name;
    int age;
    Student *next;
    Student(int code,string name,int age){
        this->code=code;
        this->name=name;
        this->age=age;
        next=NULL;
    }
};

class PriorityQueue{
    private:
    Student *head;
    
    public:
    PriorityQueue(){
        head=nullptr;
    }
    
    void enqueue(int code,string name,int age){
        Student *newStudent=new Student(code,name,age);
        if(head==NULL || head->code>code){
            newStudent->next=head;
            head=newStudent;
        }else{
            Student *current=head;
            while(current->next!=nullptr && current->next->code<=code){
                current=current->next;
            }
            newStudent->next=current->next;
            current->next=newStudent;
        }
    }
    void dequeue(){
        if(head==nullptr){
            cout<<"Queue is empty";
            return;
        }
        Student *temp=head;
        head=head->next;
        delete temp;
    }
    
    void display(){
        if(head==nullptr){
            cout<<"Queue is empty";
            return;
        }
    Student *current=head;
    while(current !=nullptr){
        cout<<current->code<<current->name<<current->age<<endl;
        current=current->next;
    }
    }
    
};
int main() {
    PriorityQueue pq;

    // Sample students
    pq.enqueue(3, "Alice", 22);
    pq.enqueue(1, "Bob", 25);  // Highest priority (lowest code)
    pq.enqueue(4, "Charlie", 20);
    pq.enqueue(2, "Diana", 28);

    // Display queue
    pq.display();

    // Dequeue the student with the highest priority (lowest code)
    pq.dequeue();

    // Display queue after dequeue
    pq.display();

    return 0;
}