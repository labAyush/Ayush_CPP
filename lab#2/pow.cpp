#include <iostream>

int pow(int x, int n)
{
    float result = 1.0;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}
    int main()
    {
        std::cout << "\n"
             << pow(3, 3);
        return 0;
    }
