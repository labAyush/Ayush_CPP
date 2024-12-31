#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <stdexcept>
using namespace std;

// Utility function to print decorative separators
void printSeparator(char ch = '=', int length = 50) {
    for (int i = 0; i < length; ++i) cout << ch;
    cout << endl;
}

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() const {
        cout << left << setw(20) << "Name" << ": " << name << endl;
        cout << left << setw(20) << "Age" << ": " << age << endl;
    }
};

// Derived class: Patient
class Patient : public Person {
private:
    string healthIssue;
    string doctor;
public:
    Patient() : Person(), healthIssue(""), doctor("") {}
    Patient(string n, int a, string ail, string doc) : Person(n, a), healthIssue(ail), doctor(doc) {}

    void display() const override {
        printSeparator('-', 70);
        cout << "| " << left << setw(20) << "Name"
             << "| " << setw(5) << "Age"
             << "| " << setw(20) << "Health Issue"
             << "| " << setw(20) << "Doctor"
             << "|" << endl;
        printSeparator('-', 70);
        cout << "| " << setw(20) << name
             << "| " << setw(5) << age
             << "| " << setw(20) << healthIssue
             << "| " << setw(20) << doctor
             << "|" << endl;
        printSeparator('-', 70);
    }

    // Friend function
    friend void savePatientToFile(const Patient& p);
};

// Class: Billing
class Billing {
private:
    int daysAdmitted;
    int ratePerDay;
public:
    Billing(int days = 0, int rate = 0) : daysAdmitted(days), ratePerDay(rate) {}

    int calculateBill() const {
        return daysAdmitted * ratePerDay;
    }

    void displayBill() const {
        cout << "\nBilling Summary:" << endl;
        printSeparator('-', 30);
        cout << left << setw(20) << "Days Admitted" << ": " << daysAdmitted << endl;
        cout << left << setw(20) << "Rate Per Day ($)" << ": $" << ratePerDay << endl;
        cout << left << setw(20) << "Total Bill ($)" << ": $" << calculateBill() << endl;
        printSeparator('-', 30);
    }
};

// Utility function to save patient to file
void savePatientToFile(const Patient& p) {
    ofstream out("D:/Patients.txt", ios::app);
    if (!out) {
        throw runtime_error("Error: Unable to open file for writing!");
    }
    out << p.name << " | " << p.age << " | " << p.healthIssue << " | " << p.doctor << endl;
    out.close();
}

// Utility function to read and display all patients from file
void displayPatientsFromFile() {
    ifstream in("D:/Patients.txt");
    if (!in) {
        throw runtime_error("Error: Unable to open file for reading!");
    }
    cout << "\nRegistered Patients:" << endl;
    printSeparator('-', 70);
    cout << "| " << left << setw(20) << "Name"
         << "| " << setw(5) << "Age"
         << "| " << setw(20) << "Health Issue"
         << "| " << setw(20) << "Doctor"
         << "|" << endl;
    printSeparator('-', 70);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string name, healthIssue, doctor;
        int age;
        getline(ss, name, '|');
        ss >> age;
        ss.ignore();
        getline(ss, healthIssue, '|');
        getline(ss, doctor);

        cout << "| " << left << setw(20) << name
             << "| " << setw(5) << age
             << "| " << setw(20) << healthIssue
             << "| " << setw(20) << doctor
             << "|" << endl;
    }
    printSeparator('-', 70);
    in.close();
}

// Class for Polymorphism Example
class HospitalService {
public:
    virtual void displayService() const = 0; // Pure virtual function
};

class RoomService : public HospitalService {
private:
    string roomType;
public:
    RoomService(string type = "General") : roomType(type) {}

    void displayService() const override {
        cout << "\nRoom Service:" << endl;
        printSeparator('-', 30);
        cout << "Room Type: " << roomType << " room provided." << endl;
        printSeparator('-', 30);
    }
};

// Main Function
int main() {
    try {
        bool exit = false;

        while (!exit) {
            system("cls");
            int choice;

            cout << "\t===============================" << endl;
            cout << "\t   Hospital Management System" << endl;
            cout << "\t===============================" << endl;
            cout << "\t1. Register Patient" << endl;
            cout << "\t2. Display Patients" << endl;
            cout << "\t3. Generate Bill" << endl;
            cout << "\t4. Room Service" << endl;
            cout << "\t5. Exit" << endl;
            cout << "\tEnter your choice: ";
            cin >> choice;

            if (choice == 1) {
                system("cls");
                string name, healthIssue, doctor;
                int age;

                cout << "\tRegister Patient:" << endl;
                printSeparator('-', 30);
                cout << "\tEnter Patient Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\tEnter Patient Age: ";
                cin >> age;
                cout << "\tEnter Health Issue: ";
                cin.ignore();
                getline(cin, healthIssue);
                cout << "\tEnter Assigned Doctor: ";
                getline(cin, doctor);

                Patient p(name, age, healthIssue, doctor);
                savePatientToFile(p);
                cout << "\n\tPatient Registered Successfully!" << endl;
                Sleep(3000);
            } else if (choice == 2) {
                system("cls");
                displayPatientsFromFile();
                Sleep(5000);
            } else if (choice == 3) {
                system("cls");
                int days, rate;
                cout << "\tGenerate Bill:" << endl;
                printSeparator('-', 30);
                cout << "\tEnter Number of Days Admitted: ";
                cin >> days;
                cout << "\tEnter Rate Per Day ($): ";
                cin >> rate;

                Billing b(days, rate);
                b.displayBill();
                Sleep(5000);
            } else if (choice == 4) {
                system("cls");
                string roomType;
                cout << "\tRoom Service:" << endl;
                printSeparator('-', 30);
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
                cout << "\tInvalid Choice! Please try again." << endl;
                Sleep(2000);
            }
        }
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        Sleep(3000);
    }
    return 0;
}
