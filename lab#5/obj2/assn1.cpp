#include<iostream>
using namespace std;
class count{
    int n;
    public:
    int num[100];
    int pos,neg,zero;
    count(){
        pos = 0;
        neg = 0;
        zero = 0;
    }
    void getn(){
        cout<<"Enter the number of terms: ";
        cin>>n;
    }
    void getnum(){
        cout<<endl<<"Enter the numbers:"<<endl;
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(num[i]<0){
                neg++;
            }
            else if(num[i]==0){
                zero++;
            }
            else{
                pos++;
            }
        }
    }
    ~count(){
        cout<<endl<<"Positive:"<<pos<<"\nNegative:"<<neg<<"\nZero:"<<zero;
    }
};
int main(){
    count a;
    a.getn();
    a.getnum();
    return 0;
}