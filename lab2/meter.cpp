#include<iostream>
float tometer(float a){
    return(a*1000);
}
float tometer(float p,float q){
    return(p*1000+q);
}
float tometer(float x,float y,float z){
    return(x*1000+y);
}
int main()
{
    std::cout<<"\n"<<tometer(6);
    std::cout<<"\n"<<tometer(8,100);
    std::cout<<"\n"<<tometer(1,20,60);
    return 0;
}
