#include <iostream>
using namespace std;
struct Queue {

    int capacity;
    int* queue;
    int front;
    int rear;
    int size;

    // Constructor to initialize the queue
    Queue(int cap) {
        capacity = cap;
        front = rear = -1;
        size = 0;
        queue = new int[capacity];
    }
    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }
    // Add an element to the queue
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Full" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % capacity; // Circular increment
            queue[rear] = val;
            size++;
        }
    }
    // Remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "The removed element is " << queue[front] << endl;
            front = (front + 1) % capacity; // Circular increment
            size--;
        }
    }
    // Get the number of elements in the queue
    int count() {
        return size;
    }
    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++) {
                int index = (front + i) % capacity; // Circular indexing
                cout << queue[index] << " ";
            }
            cout << endl;
        }
    }
    // Get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }
};
int main() {
    Queue q(5); // Create a queue with capacity 5
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Peek: " << q.peek() << endl;
    cout << "Count: " << q.count() << endl;
    q.dequeue();
    q.dequeue();
    q.display();
    cout << "Peek: " << q.peek() << endl;
    cout << "Count: " << q.count() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    return 0;
}