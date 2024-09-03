#include<iostream>
using namespace std;

class brand{
    char brand_name[10];
    float price;
public:
    void getdata(){
        cout<<"Name of item is ";
        cin>>brand_name;
        cout<<"\nPrice of item is ";
        cin>>price;
    }
    float getprice(){
        return(price);
    }
    brand& cheaper(brand &b){
        if(price>b.getprice())
            return(b);
        else
            return(*this);
    }
    void putdata(){
        cout<<"\nName of the item is "<<brand_name;
        cout<<"\nPrice of the item is "<<price;
    }
};

int main(){
    brand a,b;
    a.getdata();
    b.getdata();
    brand &cheap = a.cheaper(b);
    cheap.putdata();
    return 0;
}