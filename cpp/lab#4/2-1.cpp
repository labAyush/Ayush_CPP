#include<iostream>
using namespace std;
class product{
    int i, j, k, x;
    public:
    void set(int m, int n, int o, int x1){
        i=m;
        j=n;
        k=o;
        x=x1;
    }
    product multiply(product a){
        product b;
        b.i=x*a.i;
        b.j=x*a.j;
        b.k=x*a.k;
        return(b);
    }
    void show(){
        cout<<i<<"i+"<<j<<"j+"<<k<<"k";
    }
};
int main(){
    product x,y,z;
    x.set(2,3,4,3);
    z=x.multiply(x);
    z.show();
    return 0;
}