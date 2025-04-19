
#include<iostream>
using namespace std;
class SuperDigit
{
    public:
    int sumOfDigit(string NumberOfString)
    {
        int Sum=0;
        for(char digit:NumberOfString)
        {
            Sum+=digit-'0';
        }
        return Sum;
    }
    int SuperDigitOfNumber(string NumberOfString,int NumberOfTimes)
    {
        long long InitialSum=(long long)sumOfDigit(NumberOfString)*NumberOfTimes;
        if(InitialSum<10)
        {
            return InitialSum;
        }
        else
        {
            return SuperDigitOfNumber(to_string(InitialSum),1);
        }
    }
};
int main()
{
    string NumberOfString;
    int NumberOfTimes;
    cout<<"Enter the Number as a string: ";
    cin>>NumberOfString;
    cout<<"Enter the Number of times you want to repeat the number : ";
    cin>>NumberOfTimes;
    SuperDigit s;
    cout<<"The Super Digit of "<<NumberOfString<<" is : "<<s.SuperDigitOfNumber(NumberOfString,NumberOfTimes)<<endl;
    cout << "24CE001_Satvi_Akola" << endl;
    return 0;
}
