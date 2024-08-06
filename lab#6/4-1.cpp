#include<iostream>
#include<cstring>
using namespace std;
const int sz=50;
class String{
    char str[sz];
    public:
    String(){
        strcpy(str," ");
    }
    String(char s[]){
        strcpy(str,s);
    }
    void display(){
        cout<<str;
    }
    String operator+(String ss){
        if((strlen(str)+strlen(ss.str))<sz){
            String temp;
            strcpy(temp.str,str);
            strcat(temp.str,ss.str);
            return temp;
        }
        else{
            cout<<"\nString overflow.";
        }
    }
    String& operator+=(String ss){
        if((strlen(str)+strlen(ss.str))<sz){
            strcat(str,ss.str);
            return *this;
        }
        else{
            cout<<"\nString overflow.";
        }
    }
};
int main(){
    cout<<"Before concatenation.\n";
    String s1="Happy ";
    String s2="Birthday";
    s1.display();
    cout<<"\n";
    s2.display();
    s1+=s2;
    cout<<"\nAfter concatenation using += operator.\n";
    s1.display();
    return 0;
}