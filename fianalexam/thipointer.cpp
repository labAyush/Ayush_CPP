#include<iostream>
using namespace std;
class person{
    int age;
    public:
     void set(){
        cout<<"Enter your age:"<<endl;
        cin>>age;
     }
     person greater(person x){
        if(x.age>age){
            return x;
        }
        else{
            return *this;
        }
     }
     void display(){
        cout<<"Greater Age is "<<age<<endl;
     }
};
int main(){
    person p1,p2,p3;
    p1.set();
    p2.set();
    p3=p1.greater(p2);
    p3.display();
    return 0;
}
