#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char name[10];
    int r;
    fstream fout;
    fout.open("Student.txt",ios::out);
    cout<<"Name: ";
    cin>>name;
    cout<<"Roll no.: ";
    cin>>r;
    fout.seekg(0,ios::end);
    fout.width(4);
    fout<<r;
    fout.width(10);
    fout<<name<<endl;
    fout.close();
    fout.seekg(0,ios::beg);
    fout.open("Student.txt",ios::in);
    while(!fout.eof()){
        fout.getline(name,40);
        cout<<name<<endl;
    }
    return 0;
}
