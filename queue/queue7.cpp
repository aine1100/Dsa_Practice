#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T x)
    {
        this->data = x;
        next = NULL;
    }
};

template <typename T>
class Queue
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T ele)
    {
        Node<T> *n = new Node<T>(ele);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }
        return head->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue<double> q;
    q.enqueue(10.5);
    q.enqueue(20.3);
    q.enqueue(30.3);
    q.enqueue(40.2);
    q.enqueue(50.1);
    q.enqueue(60.5);
    q.enqueue(70.7);
    q.display();
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;
    cout << q.getSize() << endl;

    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.dequeue();
    }
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}
