#include<iostream>
using namespace std;
class complex{
    int real, img;
    public:
    void set(int r, int i){
        real=r;
        img=i;
    }
    complex add(complex a){
        complex b;
        b.real=real+a.real;
        b.img=img+a.img;
        return(b);
    }
    void show(){
        cout<<real<<"+"<<img<<"i";
    }
};
int main(){
    complex x,y,z;
    x.set(2,3);
    y.set(4,6);
    z=x.add(y);
    z.show();
    return 0;
}