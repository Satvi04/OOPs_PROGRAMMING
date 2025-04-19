#include <iostream>
#include <string>
using namespace std;

class Person {
    string Name;
    int Age;

public:
    Person() : Age(0) {} // Default constructor

    Person(string n, int a) : Name(n), Age(a) {}

    void DisplayDetails() {
        cout << "Name of Employee is " << Name << " and Age is " << Age << endl;
    }
};

class Employee : private Person {
    int id;

public:
    Employee() : id(0) {} //default constructor
    Employee(string n, int a, int i) : Person(n, a), id(i) {}

    void DisplayId() {
        Person::DisplayDetails();
        cout << "Employee I'D is: " << id << endl;
    }
};

class Manager : private Employee {
    string Department;

public:
    Manager() {} //default constructor
    Manager(string n, int a, int i, string dep) : Employee(n, a, i), Department(dep) {}

    void DisplayDepartment() {
        Employee::DisplayId();
        cout << "Employee Department is " << Department << endl;
    }
};

int main() {
    string Name, Department;
    int Age, id;

    cout << "Enter the Employee Name: ";
    getline(cin, Name);
    cout << "Enter the Employee Age: ";
    cin >> Age;
    cin.ignore(); // Consume newline
    cout << "Enter the Employee I'D: ";
    cin >> id;
    cin.ignore(); // Consume newline
    cout << "Enter the Employee Department: ";
    getline(cin, Department);

    Manager m(Name, Age, id, Department); //create object using constructor
    m.DisplayDepartment();
    cout << "24CE001_Satvi_Akola" << endl;
    return 0;
}
