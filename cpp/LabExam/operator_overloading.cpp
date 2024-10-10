#include<iostream>
using namespace std;

class time1{
    int hour, min, sec;
    public:
    void set_time(int h, int m, int s){
        hour = h;
        min=m;
        sec=s;
    }
    time1 operator +(time1 a){
        time1 temp;
        temp.sec=sec+a.sec;
        if(temp.sec>=60){
            temp.sec-=60;
            min++;
        }
        temp.min=min+a.min;
        if(temp.min>=60){
            temp.min-=60;
            hour++;
        }
        temp.hour=hour+a.hour;
        return(temp);
    }
    void display(){
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
};
int main(){
    time1 a,b,c;
    a.set_time(2,3,4);
    b.set_time(5,58,57);
    a.display();
    b.display();
    c=a+b;
    c.display();
    return 0;
}