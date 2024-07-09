#include<iostream>
using namespace std;
class time1{
    int hour,minute,second;
    public:
    void set(int h,int m,int s){
        hour=h;
        minute=m;
        second=s;
    }
    void add(time1 a, time1 b){
        hour=b.hour+a.hour;
        minute=b.minute+a.minute;
        second=b.second+a.second;
    }
    void display(){
        cout<<endl<<hour<<" hours "<<minute<<" minute "<<second<<" seconds";
    }
};
int main(){
    time1 p,q,r;
    int hh,mm,ss;
    cout<<"Enter first time(hh-mm-ss):";
    cin>>hh>>mm>>ss;
    p.set(hh,mm,ss);
    int hh1,mm1,ss1;
    cout<<endl<<"Enter second time(hh-mm-ss):";
    cin>>hh1>>mm1>>ss1;
    q.set(hh1,mm1,ss1);
    r.add(p,q);
    r.display();
    return 0;
}