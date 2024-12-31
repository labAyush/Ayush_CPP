#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Patient {
private:
    string name, ailment, doctor;
    int age;
public:
    Patient() : name(""), ailment(""), doctor(""), age(0) {}

    void setName(string patientName) {
        name = patientName;
    }

    void setAilment(string patientAilment) {
        ailment = patientAilment;
    }

    void setDoctor(string assignedDoctor) {
        doctor = assignedDoctor;
    }

    void setAge(int patientAge) {
        age = patientAge;
    }

    string getName() {
        return name;
    }

    string getAilment() {
        return ailment;
    }

    string getDoctor() {
        return doctor;
    }

    int getAge() {
        return age;
    }
};

void registerPatient(Patient p) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Register Patient." << endl;
        cout << "\t2. Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string name, ailment, doctor;
            int age;

            cout << "\tEnter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            p.setName(name);

            cout << "\tEnter Patient Age: ";
            cin >> age;
            p.setAge(age);

            cout << "\tEnter Ailment: ";
            cin.ignore();
            getline(cin, ailment);
            p.setAilment(ailment);

            cout << "\tEnter Assigned Doctor: ";
            getline(cin, doctor);
            p.setDoctor(doctor);

            ofstream out("D:/Patients.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                out << p.getName() << " : " << p.getAge() << " : " << p.getAilment() << " : " << p.getDoctor() << endl;
            }
            out.close();
            cout << "\tPatient Registered Successfully!" << endl;
            Sleep(3000);
        } else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

void displayPatients() {
    system("cls");
    ifstream in("D:/Patients.txt");

    if (!in) {
        cout << "\tNo Patients Found!" << endl;
    } else {
        string line;
        cout << "\tRegistered Patients:" << endl;
        cout << "\tName | Age | Ailment | Doctor" << endl;
        while (getline(in, line)) {
            cout << line << endl;
        }
    }
    in.close();
    Sleep(3000);
}

void generateBill() {
    system("cls");
    string patientName;
    int daysAdmitted, ratePerDay;

    cout << "\tEnter Patient Name: ";
    cin.ignore();
    getline(cin, patientName);

    cout << "\tEnter Number of Days Admitted: ";
    cin >> daysAdmitted;

    cout << "\tEnter Rate Per Day (in $): ";
    cin >> ratePerDay;

    int totalBill = daysAdmitted * ratePerDay;
    cout << "\tGenerating Bill for " << patientName << "..." << endl;
    Sleep(2000);

    cout << "\n\t********** Hospital Bill **********" << endl;
    cout << "\tPatient Name: " << patientName << endl;
    cout << "\tDays Admitted: " << daysAdmitted << endl;
    cout << "\tRate Per Day: $" << ratePerDay << endl;
    cout << "\tTotal Bill: $" << totalBill << endl;
    cout << "\t***********************************" << endl;

    Sleep(5000);
}

int main() {
    Patient p;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;

        cout << "\tWelcome To Hospital Management System" << endl;
        cout << "\t*************************************" << endl;
        cout << "\t1. Register Patient." << endl;
        cout << "\t2. Display Registered Patients." << endl;
        cout << "\t3. Generate Patient Bill." << endl;
        cout << "\t4. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            registerPatient(p);
        } else if (val == 2) {
            displayPatients();
        } else if (val == 3) {
            generateBill();
        } else if (val == 4) {
            system("cls");
            exit = true;
            cout << "\tGoodbye!" << endl;
            Sleep(3000);
        }
    }
    return 0;
}
