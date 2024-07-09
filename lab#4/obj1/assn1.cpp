#include<iostream>
using namespace std;
class age{
    int year,month,day;
    public:
    void set(int y,int m,int d){
        year=y;
        month=m;
        day=d;
    }
    void sub(age a, age b){
        year=b.year-a.year;
        month=b.month-a.month;
        day=b.day-a.day;
    }
    void display(){
        cout<<endl<<"You are"<<year<<" years "<<month<<" month "<<day<<" days old";
    }
};
int main(){
    age p,q,r;
    int yy,mm,dd;
    cout<<"Enter your dob(yy-mm-dd):";
    cin>>yy>>mm>>dd;
    p.set(yy,mm,dd);
    int yy1,mm1,dd1;
    cout<<endl<<"Enter todays date(yy-mm-dd):";
    cin>>yy1>>mm1>>dd1;
    q.set(yy1,mm1,dd1);
    r.sub(p,q);
    r.display();
    return 0;
}