#include<iostream>
#include<cmath>
using namespace std;

class wall{
    float l,v,b,h,V,N;
    float vol(){
        return(l*b*h);
    }
    float number(){
        V=vol();
        return (V/v);
    }
public:
    float c;
    void setdata(float a,float br,float c){
        l=a;
        b=br;
        h=c;
    }
    void setvol(float x){
        v=x;
    }
    void setrate(float r){
        c=r;
    }
    float cost(){
        N=number();
        return(c*N);
    }
    float getVolume(){
        return vol();
    }
    float getNumBricks(){
        return number();
    }
};

int main(){
    wall w;
    w.setdata(6,5,4);
    w.setvol(0.5);
    w.setrate(2.5);
    cout<<"The volume of the wall is: "<<w.getVolume()<<endl;
    cout<<"The number of bricks used is: "<<w.getNumBricks()<<endl;
    cout<<"The total cost is: "<<w.cost()<<endl;
    return 0;
}