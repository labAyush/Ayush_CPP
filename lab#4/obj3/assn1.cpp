#include<iostream>
using namespace std;

class Brick;

class Wall {
    private:
        int length;
        int height;
    public:
        void setDimensions(int l, int h) {
            length = l;
            height = h;
        }
        friend float totalCost(Wall, Brick);
};

class Brick {
    private:
        float cost;
    public:
        void setCost(float c) {
            cost = c;
        }
        friend float totalCost(Wall, Brick);
};

float totalCost(Wall w, Brick b) {
    return w.length * w.height * b.cost;
}

int main() {
    Wall w;
    Brick b;
    w.setDimensions(10, 5);
    b.setCost(10.5);
    cout << "The total cost of constructing the wall is: " << totalCost(w, b) << endl;
    return 0;
}