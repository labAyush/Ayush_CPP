#include <fstream>
#include <iostream>

using namespace std;

int main() {
  char ch;
  ifstream fin;
  ofstream fout;
  fin.open("source.txt", ios::in);
  fout.open("destination.txt", ios::out);
  while (fin.get(ch)) {
    fout.put(ch);
  }
  fin.close();
  fout.close();
  return 0;
}