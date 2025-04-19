#include <iostream>
using namespace std;
class ram
{
public:
    template <typename T>
  T FindMax(T arr[], int n)
    {
        T max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
    template <typename T>
    void ReverseArray(T arr[], int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(arr[i], arr[n - i - 1]);
        }
    }
    template <typename T>
    void DisplayArray(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    ram r;
    int IntArray[] = {25, 29, 35, 43, 57};
    float FloatArray[]={54.35,23.45,67.89,12.34,56.78};
    char CharArray[]={'a','b','c','d','e'};
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"From Integer Typr Array : "<<endl;
    r.DisplayArray(IntArray,5);
    cout<<"If we trying to find the maximum value : "<<r.FindMax(IntArray,5)<<endl;
    cout<<"If this will Reversing : "<<endl;
    r.ReverseArray(IntArray,5);
    r.DisplayArray(IntArray,5);
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"From Float Typr Array : "<<endl;
    r.DisplayArray(FloatArray,5);
    cout<<"If we trying to find the maximum value : "<<r.FindMax(FloatArray,5)<<endl;
    cout<<"If this will Reversing : "<<endl;
    r.ReverseArray(FloatArray,5);
    r.DisplayArray(FloatArray,5);
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"From Char Typr Array : "<<endl;
    r.DisplayArray(CharArray,5);
    cout<<"If we trying to find the maximum value : "<<r.FindMax(CharArray,5)<<endl;
    cout<<"If this will Reversing : "<<endl;
    r.ReverseArray(CharArray,5);
    r.DisplayArray(CharArray,5);

    cout << "24CE001_Satvi_Akola" << endl;
    return 0;
}
