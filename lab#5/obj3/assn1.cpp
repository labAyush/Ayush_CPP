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
    time1 add(time1 a){
        time1 b;
        b.hour=hour+a.hour;
        b.minute=minute+a.minute;
        b.second=second+a.second;
        return(b);
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
    r=p.add(q);
    r.display();
    return 0;
}
