#include <iostream>
using namespace std;
class student {
private:
  char name[10], address[20], sem[5], faculty[25];
  int crn;

public:
  void getdata() {
    cout << "Enter the details of a student:\n";
    cout << "Name:";
    cin >> name;
    cout << "\nAddress:";
    cin >> address;
    cout << "\nSememster:";
    cin >> sem;
    cout << "\nFaculty:";
    cin >> faculty;
    cout << "\nCollege roll no:";
    cin >> crn;
  }
  void display() {
    cout << "\nThe details of the students are as follows:\n";
    cout << "Name:" << name;
    cout << "\nAddress:" << address;
    cout << "\nSememster:" << sem;
    cout << "\nFaculty:" << faculty;
    cout << "\nCollege roll no:" << crn;
  }
};
int main() {
  student *ps;
  student s;
  ps = &s;
  ps->getdata();
  ps->display();
  return 0;
}