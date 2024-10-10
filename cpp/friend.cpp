#include<iostream>
using namespace std;

class complex2;

class complex1{
    int real, img;
    public:
        complex1()
        {}
        complex1(int r, int i){
            real = r;
            img = i;
        }
        friend void add(complex1,complex2);
        void display(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
};
class complex2{
    int real,img;
    public:
        complex2()
        {}
        complex2(int r, int i){
            real = r;
            img = i;
        }
        friend void add(complex1,complex2);
        void display(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
};
void add(complex1 A, complex2 B){
    A.real = A.real+ B.real;
    A.img = A.img + B.img;
    A.display();
}
int main(){
    complex1 A(4,5);
    complex2 B(1,2);
    A.display();
    B.display();
    add(A,B);
    return 0;
}