#include<iostream>
using namespace std;
class complex{
    int real, img;
    public:
        complex()
        {}
        complex(int r, int i){
            real=r;
            img=i;
        }
        complex operator+(complex a){
            complex b;
            b.real=real+a.real;
            b.img=img+a.img;
            return b;
        }
        void display(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
};
int main(){
    complex x(2,3),y(3,4),z;
    x.display();
    y.display();
    z=x+y;
    z.display();
    return 0;
}