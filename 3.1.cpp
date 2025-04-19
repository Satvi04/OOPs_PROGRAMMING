#include<iostream>
using namespace std;
class Employee
{
    string Name;
    int Salary;
    int Bonus;
    int TotalSalary;

public:
    Employee()//default constructor
    {
        Bonus=1500;//default Bonus
    }
    Employee(string NoOfEmployee,int s,int b)//parametarised constructor
    {
        Name=NoOfEmployee;
        Salary=s;
        Bonus=b;
        TotalSalary=CalculateTotalSalary();
    }
    inline int CalculateTotalSalary()//inline function
    {
        return TotalSalary=Salary+Bonus;
    }
    void Display()
    {
        cout<<"Name of Employee: "<<Name<<endl;
        cout<<"Salary of Employee: "<<Salary<<endl;
        cout<<"Bonus of Employee: "<<Bonus<<endl;
        cout<<"Total Salary of Employee: "<<TotalSalary<<endl<<endl;
    }

};

int main()
{
    int NoOfEmployee;
    cout<<"Enter the Number of Employee you want to Add the Datas For:";
    cin>>NoOfEmployee;
    Employee** e = new Employee*[NoOfEmployee];

    for(int i=0;i<NoOfEmployee;i++)
    {
        string Name;
        int Bonus,Salary;
        string ExtraBonus;
        cout<<"Enter the Name of the Emplyoee "<< i+1 << ":";
        cin>>Name;
        cout<<"Enter the Salary of Employee " <<i+1<<":";
        cin>>Salary;
        cout<<"Do you wnat to enter eExtraBonustra Bonus for this Employee? (y/NoOfEmployee)";
        cin>>ExtraBonus;
        if(ExtraBonus=="y" || ExtraBonus=="Y")
        {
            cout<<"Enter the Bonus ammount you want to add for Employee " <<i+1<<":";
            cin>>Bonus;
            e[i]= new Employee(Name,Salary,Bonus);


        }
        else if (ExtraBonus=="NoOfEmployee" || ExtraBonus=="N")
        {
            cout<<"Applying Default Bonus for this Employee"<<endl;
            e[i]=new Employee(Name,Salary,1500);
        }
        else
        {
            cout<<"Please Enter a Valid Choice"<<endl;
        }
       cout<<endl;

    }
    for (int i=0;i<NoOfEmployee;i++)
    {
        cout<<"Details Of the Employee "<<i+1<<":"<<endl;
        e[i]->Display();
    }
    for (int i = 0; i < NoOfEmployee; i++)
    {
        delete e[i];
    }
    cout<<"24CE001_Satvi_Akola";
}
