#include<iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enQueue(int ele) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = ele;
            cout << "Added element: " << ele << endl;
        }
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int element = items[front];
        if (front == rear) {
            // Queue becomes empty after removing the element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);

    // Attempt to add an element when the queue is full
    q.enQueue(60);

    // Display the queue
    q.display();

    // Dequeue a few elements
    cout << "Dequeued element: " << q.deQueue() << endl;
    cout << "Dequeued element: " << q.deQueue() << endl;

    // Display the queue again
    q.display();

    // Add more elements
    q.enQueue(60);
    q.enQueue(70);

    // Display the queue again
    q.display();

    return 0;
}
