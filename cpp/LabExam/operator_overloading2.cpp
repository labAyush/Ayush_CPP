#include<iostream>
using namespace std;
class matrix{
    int a[3][3],i,j;
    public:
    void set(){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
    }
    void operator+(matrix &m2){

        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                a[i][j]+=m2.a[i][j];
            }
        }
    }
    void display(){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cout<<a[i][j]<<"\t";
            }
        cout<<"\n";
        }
    }
};
int main(){
    matrix m1,m2;
    m1.set();
    m2.set();
    m1+m2;
    m1.display();
    return 0;
}