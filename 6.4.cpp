#include <iostream>
using namespace std;


class Base
{
public:
    Base()
    {
        cout << "Base constructor called\n";
    }


    virtual ~Base()
    {
        cout << "Base destructor called\n";
    }
};


class Derived : public Base
{
private:
    int* data;

public:
    Derived()
    {
        data = new int[5];
        cout << "Derived constructor called (allocated memory)\n";
    }

    ~Derived()
    {
        delete[] data;
        cout << "Derived destructor called (freed memory)\n";
    }
};

int main()
{

    Base* obj = new Derived();


    delete obj;


    return 0;
}

