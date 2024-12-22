#include<iostream>
using namespace std;
class number{
    int a,b;
    public:
    number(){ //default constructor
        a=13;
    }
    number(int x){ //parameterized constructor
        a=x;
    }
    number(number &obj){ //copy constructor
        cout<<"Copy constructor called."<<endl;
        a=obj.a;
    }
    void display(){
        cout<<"The number is:"<<a<<endl;
    }
};
int main(){
    number n1,n2(5);
    n1.display();
    n2.display();
    number n3(n1);
    n3.display();
    return 0;
}