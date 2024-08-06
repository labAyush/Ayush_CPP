#include<iostream>
using namespace std;
struct sphere{
    float r;
}s;
void set(float a){
    s.r=a;
}
float vol(){
    return(4*3.14*s.r*s.r*s.r/3);
}
int main(){
    set(2);
    float v=vol();
    cout<<"The volume of the sphere is:"<<v;
    return 0;
}