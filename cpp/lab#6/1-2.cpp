#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    // Overload ++ increment operator
    void operator++() {
        count++;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter counter;

    std::cout << "Initial count: " << counter.getCount() << std::endl;
    ++counter;
    std::cout << "Count after ++: " << counter.getCount() << std::endl;

    return 0;
}