#include <iostream>
using namespace std;

struct Student {
    int code;
    string name;
    int age;
    Student* next;

    Student(int stucode, string stuname, int stuage) {
        code = stucode;
        name = stuname;
        age = stuage;
        next = nullptr; //  Initialize next to nullptr
    }
};

class PriorityQueue {
private:
    Student* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Check if the queue is full (Heap memory exhausted)
    bool isFull() {
        Student* temp = new (nothrow) Student(0, "", 0);
        if (!temp) return true;
        delete temp;
        return false;
    }

    // Insert in priority order (ascending by code)
    void insert(int code, string name, int age) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert new student.\n";
            return;
        }

        Student* newStudent = new Student(code, name, age);

        if (isEmpty() || head->code > code) {
            newStudent->next = head;
            head = newStudent;
            return;
        }

        Student* current = head;
        while (current->next && current->next->code < code) {
            current = current->next;
        }

        newStudent->next = current->next;
        current->next = newStudent;
    }

    // Remove a student by code
    void remove(int code) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        if (head->code == code) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted student with code: " << code << endl;
            return;
        }

        Student* current = head;
        while (current->next && current->next->code != code) {
            current = current->next;
        }

        if (current->next) {
            Student* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Deleted student with code: " << code << endl;
        } else {
            cout << "Student with code " << code << " not found.\n";
        }
    }

    // Display students in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Students in Priority Queue:\n";
        Student* current = head;
        while (current) {
            cout << "Code: " << current->code << ", Name: " << current->name << ", Age: " << current->age << endl;
            current = current->next;
        }
    }

    // Get the front (first) student
    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front Student -> Code: " << head->code << ", Name: " << head->name << ", Age: " << head->age << endl;
    }

    // Get the rear (last) student
    void getRear() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Student* current = head;
        while (current->next) {
            current = current->next;
        }
        cout << "Rear Student -> Code: " << current->code << ", Name: " << current->name << ", Age: " << current->age << endl;
    }

    // Destructor to free memory
    ~PriorityQueue() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to test the Priority Queue
int main() {
    PriorityQueue queue;

    queue.insert(1, "Abayo", 20);
    queue.insert(5, "Dushimire", 19);
    queue.insert(3, "Kalisa", 21);
    queue.insert(2, "Fanny", 18);

    queue.display(); // Should be sorted by code

    queue.getFront(); // Get the first student
    queue.getRear();  // Get the last student

    queue.remove(5); // Delete code 5 student
    queue.display(); // Check after deletion

    queue.getFront(); // Get the new front student
    queue.getRear();  // Get the rear student

    return 0;
}
