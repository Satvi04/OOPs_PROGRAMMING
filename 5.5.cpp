#include <iostream>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0; // Pure virtual function
    virtual ~Shape() {}              // Virtual destructor
};

class Rectangle : public Shape {
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }
};

class Circle : public Shape {
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    int numShapes;
    cout << "Enter the number of shapes: ";
    cin >> numShapes;

    Shape** shapes = new Shape*[numShapes];

    for (int i = 0; i < numShapes; ++i) {
        int choice;
        cout << "\nShape " << i + 1 << ": \n";
        cout << "Enter 1 for Rectangle, 2 for Circle: ";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            shapes[i] = new Rectangle(l, w);
        } else if (choice == 2) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapes[i] = new Circle(r);
        } else {
            cout << "Invalid choice. Skipping shape.\n";
            shapes[i] = nullptr;
        }
    }

    cout << "\n--- Shape Areas ---\n";
    for (int i = 0; i < numShapes; ++i) {
        if (shapes[i]) {
            cout << "Shape " << i + 1 << " Area: " << shapes[i]->Area() << endl;
        }
    }

    // Clean up memory
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}
