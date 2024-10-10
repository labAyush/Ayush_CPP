#include<iostream>
#include<math.h>

using namespace std;

class Complex {
    float real, img;
public:
    void getdata(){
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imginary part: ";
        cin >> img;
    }

    float modulus() {
        return sqrt(real * real + img * img);
    }

    void putdata(){
        cout << "\nComplex number is " << real << " + " << img << "i";
    }

    Complex& greatm(Complex &b) {
        if (modulus() > b.modulus())
            return (*this);
        else
            return (b);
    }
};

int main(){
    Complex a, b;
    a.getdata();
    b.getdata();
    Complex &greater = a.greatm(b);
    cout << "\nComplex number with greater modulus is: ";
    greater.putdata();
    return 0;
}