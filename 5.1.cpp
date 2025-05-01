#include <iostream>
using namespace std;

class Calculator {
    int x, y, z;
    float a, b, c;

public:
    void add(int x, int y) {
        z = x + y;
    }

    void add(float a, float b) {
        c = a + b;
    }

    void display() {
        cout << "The value of int value: " << z << endl;
        cout << "The value of float value: " << c << endl;
    }
};

int main() {
    Calculator c;
    c.add(1, 2);
    c.add(1.2f, 1.2f);
    c.display();
}
