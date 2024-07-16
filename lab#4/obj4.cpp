#include<iostream>
using namespace std;
class sample{
    private:
    static int count; //declaration of static data member 
    public:
    void setcode(){
        count++;
    }
    static void showcount(){
        cout<<endl<<"count="<<count;
    }
};
int sample::count=0; //definition of the static variable initialization count is optional
int main(){
    sample s1;
    s1.setcode();
    sample::showcount();
    sample s2;
    s2.setcode();
    sample::showcount();
    sample s3;
    sample::showcount();
    return 0;
}