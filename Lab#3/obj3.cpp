#include<iostream>
using namespace std;
class sphere{
    float r;
    public:
    void set(float a)
    {
        r=a;
    }
    float vol(){
        return(4*3.14*r*r*r/3);
    }
};
int main(){
    sphere s;
    s.set(2);
    float v=s.vol();
    cout<<"The volume of the sphere is:"<<v;
    return 0;
}