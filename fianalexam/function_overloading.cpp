#include<iostream>
using namespace std;

const float pi=3.14;
float area(float r){
    return pi*r*r;
}
float area(int l, int b){
    return l*b;
}
float area(int a){
    return a*a;
}
 int main(){
    cout<<"area of circle:"<<area(3.5f)<<endl;
    cout<<"area of rectangle:"<<area(4,5);
    cout<<"area of square:"<<area(4);
    return 0;
 }