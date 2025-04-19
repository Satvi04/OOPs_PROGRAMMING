#include <iostream>
#include <string>
using namespace std;

class Fuel
{
    string FuelType;

public:

    Fuel(string f)
     {
         FuelType=f;
    }

    string getFuelType()
    {
        return FuelType;
    }
};

class BrandName
{
    string Brand;

public:
    BrandName(string bn)
     {
       Brand=bn;
     }
    string getBrand()
    {
        return Brand;
    }
};

class Cars : private Fuel, private BrandName
{
    string CarName;

public:
    Cars(string f, string bn, string cn) : Fuel(f), BrandName(bn), CarName(cn) {}
    void DisplayDetails()
    {
        cout<<endl<<"--------------------------------------------------------"<<endl;
        cout << endl<<"Car Name: " << CarName << endl;
        cout << "Brand name : " << getBrand() << endl;
        cout << "Fuel Type: " << getFuelType() << endl;
    }
};

int main()
{
    string Fuel, Brand, car;
    cout << "Enter the Fuel type: ";
    getline(cin, Fuel);
    cout << "Enter the Brand name: ";
    getline(cin, Brand);
    cout << "Enter the car name: ";
    getline(cin, car);
    Cars c(Fuel, Brand, car);
    c.DisplayDetails();
    cout << "24CE001_Satvi_Akola" << endl;
    return 0;
}
