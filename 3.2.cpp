
#include <iostream>
using namespace std;
int Iterrative(int a[],int NoOfElement)
{
    int Sum;
    for (int i=0; i<NoOfElement; i++)
    {
        Sum=Sum+a[i];
    }
    return Sum;
}
int Reccursive(int a[],int NoOfElement)
{
    if (NoOfElement==0)
    {
        return 0;
    }
    return a[NoOfElement-1] + Reccursive(a,NoOfElement-1);
}
int main()
{
    int NoOfElement;
    cout<<"enter the number of elements:";
    cin>>NoOfElement;

    int* Array = new int[NoOfElement];

    cout<<"enter "<<NoOfElement<<" elements:"<<endl;
    for (int i=0; i<NoOfElement; i++)
    {
        cin>>Array[i];

    }

    int i=Iterrative(Array,NoOfElement);
    int r=Reccursive(Array,NoOfElement);

    cout<<"Sum using Ittration: "<<i<<endl;
    cout<<"Sum using Reccursion: "<<r<<endl;

    delete[] Array;

    cout<<endl<<"24CE001_Satvi_Akola";

}
