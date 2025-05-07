

#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:

    Point(int x_val = 0, int y_val = 0)
    {
        x = x_val;
        y = y_val;
    }


    Point* moveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    void Display() const
    {
        cout << "Current Coordinates: (" << x << ", " << y << ")\n";
    }
};

int main()
{
    int x, y, n, dx, dy;


    cout << "Enter initial coordinates (x y): ";
    cin >> x >> y;


    Point* p = new Point(x, y);


    cout << "Enter number of movements: ";
    cin >> n;


    for (int i = 1; i <= n; ++i) {
        cout << "Enter dx and dy for movement " << i << ": ";
        cin >> dx >> dy;
        p->moveBy(dx, dy);
    }

    p->Display();


    delete p;

    return 0;
}

