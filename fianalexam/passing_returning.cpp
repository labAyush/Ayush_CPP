#include<iostream>
using namespace std;

class time1{
    int hour;
    int min;
    int sec;
    public:
    void set(int h,int m,int s){
        hour=h;
        min=m;
        sec=s;
    }
    time1 add(time1 a){
        time1 b;
        b.hour=hour+a.hour;
        b.min=min+a.min;
        if(b.min>=60){
            b.hour=b.hour+1;
            b.min=b.min-60;
        }
        b.sec=sec+a.sec;
        if(b.sec>=60){
            b.min=b.min+1;
            b.sec=b.sec-60;
        }
        return (b);
    }
    void show(){
        cout<<hour<<":"<<min<<":"<<sec;
        cout<<endl;
    }
};
int main(){
    time1 x,y,z;
    x.set(10,20,30);
    x.show();
    y.set(20,40,35);
    y.show();
    z = x.add(y);
    z.show();
    return 0;
}
