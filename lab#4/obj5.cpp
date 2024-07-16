#include<iostream>
using namespace std;
class prn_obj{ 
    int rno;
    char *name;
    public:
    void set_data(char *n, int r){ 
        name=n;
        rno=r;
    }
    void print(){
        cout<<this->name<<" has invoked print() function"<<endl;
        cout<<"The roll number is"<<this ->rno<<endl;
    }
};
int main(){
    prn_obj obj1,obj2,obj3;
    obj1.set_data("Suba",1);
    obj3.set_data("kayal",3);
    obj3.set_data("Jeysree",3);
    obj1.print();
    obj2.print();
    obj3.print();
    return 0;
}