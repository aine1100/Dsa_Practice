#include<iostream>
using namespace std;

int queue[100], n = 100, front = - 1, rear = - 1;
void enqueue() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow/Full"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }}
void dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow/Empty ";
      return ;
   }
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      // No need of shifting left , but this is not a better implementation
      front++;
}

void display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
		 cout<<endl;
   }
}

void readFront(){
if(front==-1){
cout<<"Queue underflow"<<endl;
return ;

}
cout<<"Element at front is:"<<queue[front]<<endl;

}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Read element from the queue"<<endl;
   cout<<"5) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
	 case 1: enqueue();
	 break;
	 case 2: dequeue();
	 break;
	 case 3: display();
	 break;
	 case 4:readFront();
	case 5: cout<<"Exited The Queue"<<endl;
		 break;
		 default: cout<<"Invalid Operation"<<endl;
      }
   } while(ch>0 && ch<5);

   return 0;
}