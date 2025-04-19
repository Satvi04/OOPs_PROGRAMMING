#include<iostream>
#include<string>
using namespace std;
class GradingFramework
{
    protected:
    string Name;
    float Marks1,Marks2,Marks3;
    public:
    virtual void getData()=0;
    virtual void CalculateAverage()=0;
    virtual void Display()=0;

};
class UGstudents : public GradingFramework
{
    public:
    void getData() override
    {
        cout<<"Enter the Name of student : ";
        cin>>Name;
        cout<<"Enter the marks of 3 subjects : ";
        cin>>Marks1>>Marks2>>Marks3;
    }
    void CalculateAverage() override
    {
        cout<<"The average of 3 subjects : "<<(Marks1+Marks2+Marks3)/3<<endl;
    }
    void Display() override
    {
        cout<<"------------------------------------------------"<<endl;
        cout<<"The Name of student : "<<Name<<endl;
        cout<<"The marks of 3 subjects : "<<Marks1<<","<<Marks2<<","<<Marks3<<endl;
        if ((Marks1+ Marks2+Marks3)/3>=40)
        {
            cout<<"The student is pass"<<endl;
        }
        else
        {
            cout<<"The student is fail"<<endl;
        }
    }
};
class PGstudents : public GradingFramework
{
    public:
    void getData() override
    {
        cout<<"Enter the Name of student : ";
        cin>>Name;
        cout<<"Enter the marks of 3 subjects : ";
        cin>>Marks1>>Marks2>>Marks3;
    }
    void CalculateAverage() override
    {
        cout<<"The average of 3 subjects : "<<(Marks1+Marks2+Marks3)/3<<endl;
    }
    void Display() override
    {
        cout<<"The Name of student : "<<Name<<endl;
        cout<<"The marks of 3 subjects (out of 100) : "<<Marks1<<","<<Marks2<<","<<Marks3<<endl;
        if ((Marks1+ Marks2+Marks3)/3>=50)
        {
            cout<<"The student is pass"<<endl;
        }
        else
        {
            cout<<"The student is fail"<<endl;
        }
    }
};
int main()
{
    UGstudents UG;
    PGstudents PG;
    GradingFramework *GF1,*GF2;
    GF1=&UG;
    GF2=&PG;
    int Number;
    cout<<"Enter 1 for UG student and 2 for PG student : ";
    cin>>Number;
    if (Number==1)
    {
        GF1->getData();
        GF1->CalculateAverage();
        GF1->Display();
    }
    else if (Number==2)
    {
        GF2->getData();
        GF2->CalculateAverage();
        GF2->Display();
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
     cout << "24CE001_Satvi_Akola" << endl;

    return 0;
}
