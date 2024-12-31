#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdexcept>
using namespace std;

// Base class: Person
class Person {
protected: // Encapsulation: Members accessible only to derived classes
    string name; // Name of the person
    int age;     // Age of the person
public:
    // Default Constructor
    Person() : name(""), age(0) {}

    // Parameterized Constructor: Initializes name and age
    Person(string n, int a) : name(n), age(a) {}

    // Virtual function for runtime polymorphism
    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    // **Possible Questions:**
    // Q1: Why is 'display' function virtual?
    // A1: To allow derived classes (like Patient) to override this function, enabling runtime polymorphism.
    // Q2: Why are 'name' and 'age' declared as protected?
    // A2: So derived classes can access them while still restricting direct access from outside the class.
};

// Derived class: Patient
class Patient : public Person {
private: // Encapsulation: Specific to the Patient class
    string ailment; // The ailment the patient is suffering from
    string doctor;  // Assigned doctor's name
public:
    // Default Constructor
    Patient() : Person(), ailment(""), doctor("") {}

    // Parameterized Constructor
    Patient(string n, int a, string ail, string doc) : Person(n, a), ailment(ail), doctor(doc) {}

    // Setters and Getters for encapsulated data
    void setAilment(string ail) { ailment = ail; }
    void setDoctor(string doc) { doctor = doc; }
    string getAilment() const { return ailment; }
    string getDoctor() const { return doctor; }

    // Overriding display function
    void display() const override {
        Person::display(); // Calling base class display
        cout << "Ailment: " << ailment << ", Doctor: " << doctor << endl;
    }

    // Friend function to save patient data to a file
    friend void savePatientToFile(const Patient& p);

    // **Possible Questions:**
    // Q1: What is the purpose of a friend function in this class?
    // A1: It allows external functions (like `savePatientToFile`) to access private/protected members.
    // Q2: Why is the `display` function overridden here?
    // A2: To provide additional details specific to a patient, like ailment and doctor.
    // Q3: Why use getters and setters instead of making variables public?
    // A3: To adhere to encapsulation principles, allowing controlled access to class data.
};

// Class: Billing
class Billing {
private:
    int daysAdmitted;  // Number of days the patient was admitted
    int ratePerDay;    // Cost per day for admission
public:
    // Constructor with default values
    Billing(int days = 0, int rate = 0) : daysAdmitted(days), ratePerDay(rate) {}

    // Calculate total bill
    int calculateBill() const {
        return daysAdmitted * ratePerDay;
    }

    // Setters for billing details
    void setDetails(int days, int rate) {
        daysAdmitted = days;
        ratePerDay = rate;
    }

    // Display billing details
    void displayBill() const {
        cout << "Days Admitted: " << daysAdmitted << ", Rate Per Day: $" << ratePerDay << endl;
        cout << "Total Bill: $" << calculateBill() << endl;
    }

    // **Possible Questions:**
    // Q1: Why is `calculateBill` declared as const?
    // A1: It doesn't modify any class members; marking it as const ensures immutability.
    // Q2: Why use a separate class for billing?
    // A2: It adheres to the principle of separation of concerns, handling billing independently.
};

// Friend function: Saves patient details to a file
void savePatientToFile(const Patient& p) {
    ofstream out("D:/Patients.txt", ios::app); // File opened in append mode
    if (!out) {
        throw runtime_error("Error: Unable to open file for writing!");
    }
    out << p.name << " : " << p.age << " : " << p.ailment << " : " << p.doctor << endl;
    out.close();
    // **Possible Questions:**
    // Q1: Why use file handling here?
    // A1: To persist patient data for future reference, enabling the system to manage records effectively.
    // Q2: What happens if the file fails to open?
    // A2: An exception is thrown using `runtime_error`, and the program handles it in the main function.
}

// Utility function to read and display all patients from the file
void displayPatientsFromFile() {
    ifstream in("D:/Patients.txt");
    if (!in) {
        throw runtime_error("Error: Unable to open file for reading!");
    }
    string line;
    cout << "\tRegistered Patients:" << endl;
    while (getline(in, line)) {
        cout << line << endl; // Display each line
    }
    in.close();
    // **Possible Questions:**
    // Q1: How does this function work?
    // A1: It reads the file line by line using `getline` and displays the content on the console.
}

// Class for Polymorphism Example: Abstract Base Class
class HospitalService {
public:
    virtual void displayService() const = 0; // Pure virtual function
};

class RoomService : public HospitalService {
private:
    string roomType; // Room type: General/Private
public:
    RoomService(string type = "General") : roomType(type) {}

    // Overriding displayService
    void displayService() const override {
        cout << "Room Service: " << roomType << " room provided." << endl;
    }

    // **Possible Questions:**
    // Q1: What is a pure virtual function?
    // A1: A function declared with `= 0` in a class, making it abstract and requiring derived classes to implement it.
    // Q2: How does polymorphism apply here?
    // A2: The base class `HospitalService` allows uniform handling of services, with specific behavior defined in derived classes.
};

// Main Function
int main() {
    try {
        bool exit = false;

        while (!exit) {
            system("cls"); // Clears the console for better UI
            int choice;

            cout << "\tHospital Management System" << endl;
            cout << "\t**************************" << endl;
            cout << "\t1. Register Patient." << endl;
            cout << "\t2. Display Patients." << endl;
            cout << "\t3. Generate Bill." << endl;
            cout << "\t4. Room Service." << endl;
            cout << "\t5. Exit." << endl;
            cout << "\tEnter your choice: ";
            cin >> choice;

            if (choice == 1) {
                system("cls");
                string name, ailment, doctor;
                int age;

                cout << "\tEnter Patient Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\tEnter Patient Age: ";
                cin >> age;
                cout << "\tEnter Ailment: ";
                cin.ignore();
                getline(cin, ailment);
                cout << "\tEnter Assigned Doctor: ";
                getline(cin, doctor);

                Patient p(name, age, ailment, doctor);
                savePatientToFile(p);
                cout << "\tPatient Registered Successfully!" << endl;
                Sleep(3000);
            } else if (choice == 2) {
                system("cls");
                displayPatientsFromFile();
                Sleep(5000);
            } else if (choice == 3) {
                system("cls");
                int days, rate;
                cout << "\tEnter Number of Days Admitted: ";
                cin >> days;
                cout << "\tEnter Rate Per Day (in $): ";
                cin >> rate;

                Billing b(days, rate);
                b.displayBill();
                Sleep(5000);
            } else if (choice == 4) {
                system("cls");
                string roomType;
                cout << "\tEnter Room Type (General/Private): ";
                cin >> roomType;

                RoomService rs(roomType);
                rs.displayService();
                Sleep(5000);
            } else if (choice == 5) {
                exit = true;
                cout << "\tGoodbye!" << endl;
                Sleep(3000);
            } else {
                cout << "\tInvalid Choice!" << endl;
                Sleep(2000);
            }
        }
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        Sleep(3000);
    }
    return 0;
}