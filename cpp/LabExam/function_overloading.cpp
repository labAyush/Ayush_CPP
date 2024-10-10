#include<iostream>
using namespace std;

const float pi=3.14;
float perimeter(int l){
    return (4*l);
}

float perimeter(int l1, int b){
    return(2*(l1+b));
}

float perimeter(float r){
    return(2*pi*r);
}

int main(){
    int l,l1,b,r;
    cout<<"Enter the length of a square: ";
    cin>>l;
    cout<<"\nThe perimeter of the square is: "<<perimeter(l);
    cout<<"\nEnter the length & breadth of a rectangle: ";
    cin>>l1>>b;
    cout<<"\nThe perimeter of the rectangle is: "<<perimeter(l1,b);
    cout<<"\nEnter the radius of a circle: ";
    cin>>r;
    cout<<"\nThe perimeter of the circle is: "<<perimeter(r);
    return 0;
}