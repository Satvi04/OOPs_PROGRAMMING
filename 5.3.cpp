#include<iostream>
using namespace std;
class point
{
    int x,y;
public:
    void InsertData()
    {
        cout<<"Enter the x and y co-ordinate:";
        cin>>x>>y;

    }

    point operator-()
    {
        point a;
        a.x=-x;
        a.y=-y;
        return a;
    }
    point operator+(point &k)
    {
        point b;
        b.x=x+k.x;
        b.y=y+k.y;
        return b;

    }
    bool operator==(point p3)
    {
        return (x == p3.x && y == p3.y);
    }
    void Display()
    {
        cout<<"( "<<x<<","<<y<<" )"<<endl;

    }
};
int main()
{
    point p1,p2,p3,p4;
    p1.InsertData();
    p2.InsertData();
    p3=p1+p2;
    cout<<"After Addition: ";
    p3.Display();
    p4=-p3;
    cout<<"After Negation: ";
    p4.Display();

    if (p1 == p2) {
        cout << "Yes, (x1,y1) and (x2,y2) are Equal\n";
    } else {
        cout << "No, (x1,y1) and (x2,y2) are not Equal\n";
    }

}
