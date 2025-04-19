#include<iostream>
using namespace std;
class Shape
{
private:
    int Radius;
public:
    void AddRadius()
    {
        cout<<"Enter the Radius: ";
        cin>>Radius;
    }
    void DisplayRadius()
    {
        cout<<"Radius of Circle is: "<<Radius<<endl;
    }
    int GetRadius()
    {
        return Radius;
    }
};
class Circle: private Shape
{
    float Area;
public:
    void CalculateArea()
    {
Shape:
        AddRadius();
        Shape::DisplayRadius();
        int a=GetRadius();
        Area=3.14*a*a;
        cout<<"Area of Circle is: "<<Area<<endl;
    }
};

int main()
{
    Circle c;
    c.CalculateArea();
    cout << "24CE001_Satvi_Akola" << endl;
}
