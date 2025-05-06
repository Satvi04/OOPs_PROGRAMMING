
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class Student
{
private:
    string Name;
    int Marks1, Marks2, Marks3;
    char Grade1, Grade2, Grade3;
    double TuitionFee;

    char GetGrade(int Marks) const
    {
        if (Marks >= 90) return 'A';
        if (Marks >= 75) return 'B';
        if (Marks >= 60) return 'C';
        if (Marks >= 50) return 'D';
        return 'F';
    }

public:
    void Input()
    {
        cout << "Enter student name: ";
        getline(cin >> ws, Name);  // ws consumes any leading whitespace

        cout << "Enter marks for subject 1: ";
        cin >> Marks1;
        Grade1 = GetGrade(Marks1);

        cout << "Enter marks for subject 2: ";
        cin >> Marks2;
        Grade2 = GetGrade(Marks2);

        cout << "Enter marks for subject 3: ";
        cin >> Marks3;
        Grade3 = GetGrade(Marks3);

        cout << "Enter tuition fee: ";
        cin >> TuitionFee;
    }

    void WriteToFile(ofstream& OutFile) const
    {
        OutFile << Name << "\n"
                << Marks1 << " " << Marks2 << " " << Marks3 << " " << TuitionFee << "\n";
    }

    bool ReadFromFile(ifstream& InFile)
    {
        if (!getline(InFile, Name)) return false;
        InFile >> Marks1 >> Marks2 >> Marks3 >> TuitionFee;
        InFile.ignore(); // consume the newline

        Grade1 = GetGrade(Marks1);
        Grade2 = GetGrade(Marks2);
        Grade3 = GetGrade(Marks3);
        return true;
    }

    void Display(ofstream& OutFile) const
    {
        OutFile << left << setw(20) << Name
                << setw(10) << Grade1
                << setw(10) << Grade2
                << setw(10) << Grade3
                << fixed << setw(14) << setprecision(2) << TuitionFee << endl;
    }

    static void PrintHeader(ofstream& OutFile)
    {
        OutFile << "\n\n"
                << setw(50) << right << "=== Student Performance Report ===\n\n";
        OutFile << left << setw(20) << "Name"
                << setw(10) << "Grade1"
                << setw(10) << "Grade2"
                << setw(10) << "Grade3"
                << setw(15) << "Tuition Fee" << endl;
        OutFile << string(65, '-') << endl;
    }
};

int main()
{
    ofstream DataOut("students.txt");
    if (!DataOut)
    {
        cerr << "Could not open students.txt for writing.\n";
        return 1;
    }

    char More;
    do
    {
        Student S;
        S.Input();
        S.WriteToFile(DataOut);

        cout << "\nDo you want to enter another student? (y/n): ";
        cin >> More;
        cin.ignore();
    }
    while (tolower(More) == 'y');
    DataOut.close();

    ifstream DataIn("students.txt");
    ofstream Report("report.txt");
    if (!DataIn || !Report)
    {
        cerr << "Error opening file for reading/writing.\n";
        return 1;
    }

    Student::PrintHeader(Report);
    Student S;
    while (S.ReadFromFile(DataIn))
    {
        S.Display(Report);
    }

    cout << "Report generated successfully in 'report.txt'.\n";
    return 0;
}
