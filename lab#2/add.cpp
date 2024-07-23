#include<iostream.h>
float f1(float a, float b)
{
	return a+b;
}
float f1(int a,int b)
{
	return a+b;
}
int main()
{
	cout<<"\n"<<f1(2.5f,2.5f);
	cout<<"\n"<<f1(2,2);
	return 0;
}
