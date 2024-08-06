#include <iostream>
using namespace std;

class Complex {
private:
  double real, imag;

public:
  Complex() {
    real = 0;
    imag = 0;
  }

  Complex(double r, double i) {
    real = r;
    imag = i;
  }

  Complex operator-() const {
    Complex temp;
    temp.real = -real;
    temp.imag = -imag;
    return temp;
  }

  void display() const {
    if (imag >= 0)
      cout << real << " + " << imag << "i" << endl;
    else
      cout << real << " - " << -imag << "i" << endl;
  }
};

int main() {
  double r, i;
  cout << "Enter the real part of the complex number: ";
  cin >> r;
  cout << "Enter the imaginary part of the complex number: ";
  cin >> i;

  Complex c(r, i);
  cout << "The complex number is: ";
  c.display();

  Complex neg = -c;
  cout << "The negation of the complex number is: ";
  neg.display();

  return 0;
}