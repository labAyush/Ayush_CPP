#include<iostream>
using namespace std;
class time1{
    int hour,min,sec;
    public:
    void set(int h,int m, int s){
        hour=h;
        min=m;
        sec=s;
    }
    time1 add(time1 a){
        time1 b;
        b.sec=sec+a.sec;
        if(b.sec>=60){
            b.sec-=60;
            min++;
        }
        b.min=min+a.min;
        if(b.min>=60){
            b.min-=60;
            hour++;
        }
        b.hour=hour+a.hour;
        return(b);
    }
    void display(){
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
 };
 int main(){
    time1 a,b,c;
    a.set(1,50,30);
    b.set(3,20,35);
    c=a.add(b);
    c.display();
 }