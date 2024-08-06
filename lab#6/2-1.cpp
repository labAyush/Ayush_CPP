#include<iostream>
using namespace std;

class Complex {
private:
    double real, img;

public:
    Complex() : real(0), img(0) {}

    Complex(double r, double i) : real(r), img(i) {}

    Complex operator+(Complex c) {
        Complex sum;
        sum.real = real + c.real;
        sum.img = img + c.img;
        return sum;
    }

    void display() {
        cout << real << " + " << img << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0), c2(2.0, 1.0), c3;
    c3 = c1 + c2;
    cout << "Sum of two complex numbers: ";
    c3.display();
    return 0;
}