#include<iostream>
using namespace std;

class complex2;
class complex1{
    int real, img;
    public:
    complex1(){}
    complex1(int i, int r){
        real = r;
        img = i;
    }
    friend void add(complex1,complex2);
    void display(){
        cout << real << " + " << img << "i" << endl;
    }
};
class complex2{
    int real, img;
    public:
    complex2(){}
    complex2(int i, int r){
        real = r;
        img = i;
    }
    friend void add(complex1,complex2);
    void display(){
        cout << real << " + " << img << "i" << endl;
    }
};
void add(complex1 a,complex2 b){
    a.real+=b.real;
    a.img+=b.img;
    a.display();
}
int main(){
    complex1 a(3,4);
    complex2 b(2,4);
    a.display();
    b.display();
    add(a,b);
    return 0;

}