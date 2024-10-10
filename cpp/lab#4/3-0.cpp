#include<iostream>
using namespace std;
class cdist;
class fdist{
    private:
    float feet;
    public:
    void set(float a){
        feet=a;
    }
    friend float add(fdist, cdist);
};
class cdist{
    private:
    float cm;
    public:
    void set(float a){
        cm=a;
    }
    friend float add(fdist, cdist);
};
float add(fdist a,cdist b){
    return(a.feet*2.5+ b.cm);
}
int main(){
    fdist f;
    cdist c;
    f.set(10);
    c.set(5);
    cout<<"The tota distance is:"<<add(f,c);
    return 0;
}