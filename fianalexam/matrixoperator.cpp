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
    friend matrix operator +(matrix m1,matrix m2){
        matrix m;
        int i,j;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                m.a[i][j]=m1.a[i][j]+m2.a[i][j];
            }
        }
        return m;
    }
    void display(){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main(){
    matrix m1,m2,m3;
    m1.set();
    m2.set();
    m3=m1+m2;
    m3.display();
    return 0;
}