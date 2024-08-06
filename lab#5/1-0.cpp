#include <iostream>
using namespace std;
int count = 0;
class condest {
public:
  condest() { cout << "\nObject Created=" << count++; }
  ~condest() { cout << "\nObject Destroyed = " << --count << endl; }
};
int main() {
  cout << "\nMain Block\n";
  condest a, b, c;
  {
    cout << "\n\nBlock 1\n";
    condest d; 
  }
  cout << "\nAgain main Block\n";
  condest e;
  return 0;
}