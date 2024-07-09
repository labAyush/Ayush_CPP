#include<iostream>
using namespace std;

class AverageCalculator;

class Student {
    private:
        string name;
        float mark1, mark2, mark3;
    public:
        void get_data() {
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter mark 1: ";
            cin >> mark1;
            cout << "Enter mark 2: ";
            cin >> mark2;
            cout << "Enter mark 3: ";
            cin >> mark3;
        }
        friend class AverageCalculator;
        void display(AverageCalculator ac) {
            cout << "Name: " << name << endl;
            cout << "Average: " << ac.mark_avg(this) << endl;
        }
};

class AverageCalculator {
    public:
        float mark_avg(Student* s) {
            return (s->mark1 + s->mark2 + s->mark3) / 3.0;
        }
};

int main() {
    Student s;
    AverageCalculator ac;
    s.get_data();
    s.display(ac);
    return 0;
}