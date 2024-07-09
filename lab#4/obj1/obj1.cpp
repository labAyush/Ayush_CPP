#include<iostream>
using namespace std;
class complex{
int real, img;
public:
void set(int r, int i){
    real=r;
    img=i;
}
void add(complex a,complex b){
    real=a.real+b.real;
    img=a.img+b.img;
}
void show(){
    cout<<real<<"+"<<img<<"i";
}
};
int main(){
    complex x,y,z;
    x.set(2,3);
    y.set(4,6);
    z.add(x,y);
    z.show();
    return 0;
}