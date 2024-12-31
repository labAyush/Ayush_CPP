#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdexcept>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
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

    void sethealthIssue(string ail) {
        healthIssue = ail;
    }

    void setDoctor(string doc) {
        doctor = doc;
    }

    string gethealthIssue() const {
        return healthIssue;
    }

    string getDoctor() const {
        return doctor;
    }

    void display() const override {
        Person::display();
        cout << "healthIssue: " << healthIssue << ", Doctor: " << doctor << endl;
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

    void setDetails(int days, int rate) {
        daysAdmitted = days;
        ratePerDay = rate;
    }

    void displayBill() const {
        cout << "Days Admitted: " << daysAdmitted << ", Rate Per Day: $" << ratePerDay << endl;
        cout << "Total Bill: $" << calculateBill() << endl;
    }
};

// Utility function to save patient to file
void savePatientToFile(const Patient& p) {
    ofstream out("D:/Patients.txt", ios::app);
    if (!out) {
        throw runtime_error("Error: Unable to open file for writing!");
    }
    out << p.name << " : " << p.age << " : " << p.healthIssue << " : " << p.doctor << endl;
    out.close();
}

// Utility function to read and display all patients from file
void displayPatientsFromFile() {
    ifstream in("D:/Patients.txt");
    if (!in) {
        throw runtime_error("Error: Unable to open file for reading!");
    }
    string line;
    cout << "\tRegistered Patients:" << endl;
    while (getline(in, line)) {
        cout << line << endl;
    }
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
        cout << "Room Service: " << roomType << " room provided." << endl;
    }
};

// Main Function
int main() {
    try {
        bool exit = false;

        while (!exit) {
            system("cls");
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
                string name, healthIssue, doctor;
                int age;

                cout << "\tEnter Patient Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\tEnter Patient Age: ";
                cin >> age;
                cout << "\tEnter healthIssue: ";
                cin.ignore();
                getline(cin, healthIssue);
                cout << "\tEnter Assigned Doctor: ";
                getline(cin, doctor);

                Patient p(name, age, healthIssue, doctor);
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
