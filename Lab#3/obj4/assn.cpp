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
};
int main(){
    wall w;
    w.setdata(6,5,4);
    w.setrate(2.5);
    cout<<"The total cost is:"<<w.cost();
    return 0;
}