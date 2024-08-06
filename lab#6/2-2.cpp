#include<iostream>
using namespace std;

class Matrix {
public:
    int data[2][2];

    Matrix(int m[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                data[i][j] = m[i][j];
            }
        }
    }

    Matrix operator+(Matrix m) {
        int sum[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                sum[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return Matrix(sum);
    }

    void display() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m1[2][2] = {{1, 2}, {3, 4}};
    int m2[2][2] = {{5, 6}, {7, 8}};

    Matrix mat1(m1);
    Matrix mat2(m2);
    Matrix mat3 = mat1 + mat2;

    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    cout << "Sum of two matrices:" << endl;
    mat3.display();

    return 0;
}