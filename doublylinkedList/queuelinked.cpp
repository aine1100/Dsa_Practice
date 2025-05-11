#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node(T x) {
        data = x;
        next = nullptr;
    }
};

template <typename T>
class Queue {
    Node<T>* head;
    Node<T>* tail;
    int size;
    
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void enqueue(T ele) {
        Node<T>* newNode = new Node<T>(ele);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    
    T front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return T();
        }
        return head->data;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node<T>* temp = head;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    // Display the queue
    q.display();
    
    // Display front element
    cout << "Front element: " << q.front() << endl;
    
    // Dequeue a few elements
    q.dequeue();
    q.dequeue();
    
    // Display the queue again
    q.display();
    
    // Display front element again
    cout << "Front element after dequeuing: " << q.front() << endl;
    
    // Check queue size and if it is empty
    cout << "Queue size: " << q.getSize() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    // Add more elements
    q.enqueue(60);
    q.enqueue(70);
    
    // Display the queue
    q.display();
    
    // Dequeue all elements
    while (!q.isEmpty()) {
        cout << "Dequeuing: " << q.front() << endl;
        q.dequeue();
    }
    
    // Check the queue after dequeuing all elements
    cout << "Queue size after clearing: " << q.getSize() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
