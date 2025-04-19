

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int Length;
    int Width;

public:

    void setDimensions(int l, int w)
    {

        Length = l;
        Width = w;

    }


    int Area()
    {
        return Length * Width;
    }


    int Perimeter()
    {
        return 2 * (Length + Width);
    }
};

int main()

{
    int n;
    cout<<endl<<"enter for how many rectangles you want to calculate data: ";
    cin>>n;

    Rectangle r[n];
    for(int i=0 ; i<n ; i++)
    {


        int l, w;
        cout << "\nEnter length and width of the rectangle:  ";
        cin >> l >> w;

        r[i].setDimensions(l, w);

        cout << "Area of the rectangle:  " << r[i].Area() << endl;
        cout << "Perimeter of the rectangle:  " << r[i].Perimeter() << endl;


    }

    cout<<endl<<endl<<"24CE001_Satvi_Akola";
    return 0;


}
