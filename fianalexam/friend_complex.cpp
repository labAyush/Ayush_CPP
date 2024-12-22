#include<iostream>
using namespace std;
class complex2;
class complex1{
    int real,img;
    public:
    void set(int r, int i){
        real=r;
        img=i;
    }
    void show(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    friend void add(complex1 a,complex2 b);
};
class complex2{
    int real,img;
    public:
    void set(int r, int i){
        real=r;
        img=i;
    }
    void show(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    friend void add(complex1 a, complex2 b);
};
void add(complex1 a,complex2 b){
    complex1 c;
    c.real=a.real+b.real;
    c.img=a.img+b.img;
    c.show();
}
int main(){
    complex1 c1;
    complex2 c2;
    c1.set(3,4);
    c1.show();
    c2.set(2,5);
    c2.show();
    add(c1,c2);
    return 0;
}