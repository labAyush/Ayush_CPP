#include<iostream>
#include<math.h>
using namespace std;
class rec
{
    double xc;
    double yc;
    public:
    rec(){
    xc=0.0;
    yc=0.0;
}
rec(double aa,double bb)
{
    xc=aa;yc=bb;
}
void display()
{
    cout<<"\nx-coordinate="<<xc;
    cout<<"\ny-coordinate="<<yc;
}
};
class polar
{
    double r;
    double a;
    public:
    polar()
        {
            r=0.0;
            a=0.0;
        }
        polar(double rr,double aa)
        {
            r=rr;
            a=aa;
        }
        void display()
        {
            cout<<"\nRadius="<<r;
            cout<<"\nAngle="<<a;
        }
        operator rec()
        {
            double x=r*cos(a);
            double y=r*sin(a);
            rec ro(x,y);
            return(ro);

        }
};
int main()
{
    rec r;
    polar p(10.0,0.785398);
    r=p;
    r.display();
    p.display();
}