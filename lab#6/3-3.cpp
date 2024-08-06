#include <iostream>
using namespace std;

class Time {
  int hours, minutes, seconds;

public:
  Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
  }
  Time(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
  }
  friend Time operator+(Time, Time);
  void display() { cout << hours << ":" << minutes << ":" << seconds << endl; }
};

Time operator+(Time t1, Time t2) {
  Time t3;
  t3.seconds = t1.seconds + t2.seconds;
  t3.minutes = t1.minutes + t2.minutes + (t3.seconds / 60);
  t3.hours = t1.hours + t2.hours + (t3.minutes / 60);
  t3.seconds = t3.seconds % 60;
  t3.minutes = t3.minutes % 60;
  return t3;
}

int main() {
  Time t1(10, 30, 45);
  Time t2(5, 45, 15);
  Time t3 = t1 + t2;

  cout << "Time 1: ";
  t1.display();
  cout << "Time 2: ";
  t2.display();
  cout << "Sum of two times: ";
  t3.display();

  return 0;
}