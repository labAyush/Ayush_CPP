#include<iostream>
using namespace std;

class complex{
    int real,img;
    public:
        void set(int r,int i){
            real=r;
            img=i;
        }
        void operator + (complex a, complex b){
            real = a.real + b.real;
            img = a.img + b.img;
        }
        void show(){
            cout<<real<<"+ i"<<img<<endl;
        }
};

int main(){
    complex c1,c2,c3;
    c1.set(3,4);
    c1.show();
    c2.set(2,5);
    c2.show();
    c1+c2;
    c3.show();
    return 0;
}