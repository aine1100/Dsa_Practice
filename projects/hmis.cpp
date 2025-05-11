#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

// Circular Queue Template
template <typename T>
class CircularQueue {
private:
    T arr[MAX_SIZE];
    int front, rear, count;
public:
    CircularQueue() : front(0), rear(-1), count(0) {}
    bool isFull() { return count == MAX_SIZE; }
    bool isEmpty() { return count == 0; }
    void enqueue(T item) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more items.\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = item;
        count++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        front = (front + 1) % MAX_SIZE;
        count--;
    }
    T getFront() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return arr[front];
    }
    void display(void (*printFunc)(T)) {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        int index = front;
        for (int i = 0; i < count; i++) {
            printFunc(arr[index]);
            index = (index + 1) % MAX_SIZE;
        }
    }
};

// Structure for Patient
struct Patient {
    int patient_id;
    string name;
    string dob;
    string gender;
};

// Structure for Doctor
struct Doctor {
    int doctor_id;
    string name;
    string specialization;
};

// Structure for Appointment
struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
};

CircularQueue<Patient> patientsQueue;
CircularQueue<Doctor> doctorsQueue;
CircularQueue<Appointment> appointmentsQueue;

// Function to validate date format (YYYY-MM-DD) and ensure it's not in the future
bool isValidDate(const string &date) {
    regex datePattern("\\d{4}-\\d{2}-\\d{2}");
    if (!regex_match(date, datePattern)) {
        return false;
    }
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    
    if (year > currentYear || (year == currentYear && month > currentMonth ) || month >12 || day >31|| (year == currentYear && month == currentMonth && day > currentDay)) {
        return false;
    }
    return true;
}

// Function to get a valid integer input
int getValidInteger(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        string input;
        cin >> input;
        try {
            size_t pos;
            value = stoi(input, &pos);
            if (pos == input.size()) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        } catch (...) {}
        cout << "Invalid input! Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to print Patient details
void printPatient(Patient p) {
    cout << "ID: " << p.patient_id << ", Name: " << p.name << ", DOB: " << p.dob << ", Gender: " << p.gender << "\n";
}

// Function to print Doctor details
void printDoctor(Doctor d) {
    cout << "ID: " << d.doctor_id << ", Name: " << d.name << ", Specialization: " << d.specialization << "\n";
}

// Function to print Appointment details
void printAppointment(Appointment a) {
    cout << "ID: " << a.appointment_id << ", Patient ID: " << a.patient_id << ", Doctor ID: " << a.doctor_id << ", Date: " << a.appointment_date << "\n";
}

void registerPatient() {
    Patient p;
    p.patient_id = getValidInteger("Enter Patient ID: ");
    cin.ignore();
    
    cout << "Enter Name: ";
    getline(cin, p.name);
    
    while (true) {
        cout << "Enter Date of Birth (YYYY-MM-DD): ";
        getline(cin, p.dob);
        if (isValidDate(p.dob)) break;
        cout << "Invalid date! Ensure it follows YYYY-MM-DD format and is not in the future.\n";
    }
    
    while (true) {
        cout << "Enter Gender (Male/Female): ";
        getline(cin, p.gender);
        
        // Convert input to lowercase for case-insensitive comparison
        string genderLower = p.gender;
        for (char &c : genderLower) c = tolower(c);

        if (genderLower == "male" || genderLower == "female") {
            // Normalize gender format (capitalize first letter)
            p.gender[0] = toupper(p.gender[0]);
            for (size_t i = 1; i < p.gender.size(); i++) {
                p.gender[i] = tolower(p.gender[i]);
            }
            break;
        }
        cout << "Invalid input! Gender must be either 'Male' or 'Female'.\n";
    }

    patientsQueue.enqueue(p);
    cout << "Patient registered successfully!\n";
}


// Function to register a doctor
void registerDoctor() {
    Doctor d;
    d.doctor_id = getValidInteger("Enter Doctor ID: ");
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, d.name);
    cin.ignore();
    cout << "Enter Specialization: ";
    getline(cin, d.specialization);
    doctorsQueue.enqueue(d);
    cout << "Doctor registered successfully!\n";
}

// Function to register an appointment
void registerAppointment() {
    Appointment a;
    a.appointment_id = getValidInteger("Enter Appointment ID: ");
    a.patient_id = getValidInteger("Enter Patient ID: ");
    a.doctor_id = getValidInteger("Enter Doctor ID: ");
    cin.ignore();
    while (true) {
        cout << "Enter Appointment Date (YYYY-MM-DD): ";
        getline(cin, a.appointment_date);
        if (isValidDate(a.appointment_date)) break;
        cout << "Invalid date! Ensure it follows YYYY-MM-DD format and is not in the future.\n";
    }
    appointmentsQueue.enqueue(a);
    cout << "Appointment registered successfully!\n";
}

int main() {
    int choice;
    do {
        cout << "\nHospital Management System\n";
        cout << "1: Register Patient\n2: Register Doctor\n3: Register Appointment\n4: Display Patients\n5: Display Doctors\n6: Display Appointments\n7: Exit\nEnter choice: ";
        choice = getValidInteger("");
        switch (choice) {
            case 1: registerPatient(); break;
            case 2: registerDoctor(); break;
            case 3: registerAppointment(); break;
            case 4: patientsQueue.display(printPatient); break;
            case 5: doctorsQueue.display(printDoctor); break;
            case 6: appointmentsQueue.display(printAppointment); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
