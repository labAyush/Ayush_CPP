#include<iostream>
using namespace std;
struct sphere{
    float r;
    void set(float a){
        r=a;
    }
    float vol(){
        return(4*3.14*r*r*r/3);
    }
};
int main(){
    struct sphere s;
    s.set(2);
    float v=s.vol();
    cout<<"The volume of the sphere is:"<<v;
    return 0;
}