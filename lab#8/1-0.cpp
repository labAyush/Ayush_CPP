#include<iostream>
using namespace std;
class mess{
    char str[50];
    public:
    void read(){
        cout<<"String is: ";
        cin.getline(str,50);
    }
    void display(){
        cout<<endl<<str;
    }
};
int main(){
    mess m;
    m.read();
    m.display();
    return 0;
}