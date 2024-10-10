#include<iostream>
using namespace std;

class condest{
    public:
    static int count;  //static int declaration
    condest(){
        cout<<"\n Object Created="<<count++;
    }
    ~condest(){
        cout<<"\nObject Destroyed = "<<--count;
    }
};

int condest::count = 0;  //static int definition

int main(){
    cout<<"\nMain Block\n";
    condest a,b,c;
    {
        cout<<"\nBlock 1\n";
        condest d;
    }
    cout<<"\nAgain main Block\n";
    condest e;
    return 0;
}