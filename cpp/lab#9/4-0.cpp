#include<iostream>
#include<string>
using namespace std;
class Student {
protected:
    string name;
    int rollNo;
public:
    Student(string n, int r) : name(n), rollNo(r) {}
    virtual void display() = 0;
    string getName() {
        return name;
    }
    int getRollNo() {
        return rollNo;
    }
};
class Engineering : public Student {
public:
    Engineering(string n, int r) : Student(n, r) {}
    void display() {
        cout << "Engineering Student: " << getName() << " (Roll No: " << getRollNo() << ")" << endl;
    }
};
class Science : public Student {
public:
    Science(string n, int r) : Student(n, r) {}
    void display() {
        cout << "Science Student: " << getName() << " (Roll No: " << getRollNo() << ")" << endl;
    }
};
class Medical : public Student {
public:
    Medical(string n, int r) : Student(n, r) {}
    void display() {
        cout << "Medical Student: " << getName() << " (Roll No: " << getRollNo() << ")" << endl;
    }
};
int main() {
    Engineering eng("Ayush", 101);
    Science sci("Romis", 102);
    Medical med("Bikram", 103);
    Student* students[3];
    students[0] = &eng;
    students[1] = &sci;
    students[2] = &med;
    for (int i = 0; i < 3; i++) {
        students[i]->display();
    }
    return 0;
}