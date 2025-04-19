


#include<iostream>
#include<string.h>
using namespace std;


 class Student
 {
     int Rollnumber;
     string Name;
     int Marks[3];
public:
     //default
     Student()
     {
     Rollnumber=0;
     Name="default name";
     Marks[0]=Marks[1]=Marks[2]=0;
     }


     //parameterazid
     Student(int r,string n,int m1,int m2,int m3)
     {
         Rollnumber=r;
         Name=n;
         Marks[0]=m1;
         Marks[1]=m2;
         Marks[2]=m3;


     }

     //function to calculate average


     double calculateAverage()
     {
         return (Marks[0]+Marks[1]+Marks[2])/3.0;
     }


     //function to Display details


     void Display()

     {
         cout<<"ROLL NUMBER :" <<Rollnumber<<endl;
         cout<<"NAME : "<<Name<<endl;
         cout<<"AVERAGE MARKS : "<<calculateAverage()<<endl;

     }
 };


 int main()
 {
     Student s[3];


     for(int i=0; i<3 ; i++)
     {


     int roll,m1,m2,m3;
     string name;

     //entering details

      cout<<"Enter details for Student "<<i+1<<endl;
      cout<<"enter roll number :";
      cin>>roll;
      cout<<"enter name :";
      cin>>name;
      cout<<"enter Marks of three subjects :";
      cin>>m1>>m2>>m3;


      s[i]=Student(roll,name,m1,m2,m3);

     }

     //displaying details

     for(int i=0 ; i<3 ; i++)
     {
         cout<<endl<<"Student "<<i+1<<"Details :"<<endl;
         s[i].Display();
     }


cout<<endl<<endl<<"24CE001_Satvi_Akola";

     return 0;
 }
