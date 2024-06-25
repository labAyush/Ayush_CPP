#include<iostream>
#include<cmath>
using namespace std;
class sphere{
    float d;
    float v1;
    float v2;
    float s;
    public:
    void set(float a,float b)
    {
        s=a+b;
    }
    float dia(){
        return(cbrt(6*s/3.14));
    }
};
int main(){
    sphere s;
    s.set(27,82);
    float v=s.dia();
    cout<<"The diameter of the sphere is:"<<v;
    return 0;
}
