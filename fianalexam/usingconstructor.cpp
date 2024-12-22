#include<iostream>
using namespace std;
class time2;
class time1{
    int hour,min,sec;
    public:
    time1(){}
    time1(int h,int m,int s){
        hour=h;
        min=m;
        sec=s;
    }
    void show(){
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
    friend void add(time1,time2);
};
class time2{
    int hour,min,sec;
    public:
    time2(){}
    time2(int h,int m,int s){
        hour=h;
        min=m;
        sec=s;
    }
    void show(){
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
    friend void add(time1,time2);
};
void add(time1 a,time2 b){
    time1 t;
    t.hour=a.hour+b.hour;
    t.min=a.min+b.min;
    if(t.min>=60){
        t.hour++;
        t.min=t.min-60;
    }
    t.sec=a.sec+b.sec;
    if(t.sec>=60){
        t.min++;
        t.sec=t.sec-60;
    }
    t.show();
}
int main(){
    time1 t1(10,30,45);
    time2 t2(20,30,50);
    t1.show();
    t2.show();
    add(t1,t2);
    return 0;
}