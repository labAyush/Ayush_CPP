#include<iostream>

int sum(int a,int b){
    return a+b;
}
float sum(float x,float y){
    return x+y;
}
int main(){
    std::cout<<"\n"
            <<sum(5,6);
    std::cout<<"\n"
            <<sum(5.0f,6.0f);
    return 0;
}