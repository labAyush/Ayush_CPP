#include<iostream>
using namespace std;
class complex{
    int real, img;
    public:
    complex(){}
    complex(int r, int i){
        real=r;
        img=i;
    }
    complex(complex &c1){
        real=c1.real;
        img=c1.img;
    }
    complex add(complex c1){
        complex c;
        c.real=real+c1.real;
        c.img=img+c1.img;
        return (c);
    }
    ~complex(){
        cout<<"Destructor is called for ";
        cout<<real<<"+i"<<img<<endl;
    }
};
int main(){
    complex c1(5, 6);
    complex c2(c1);
    complex c3 = c1.add(c2);
    return 0;
}