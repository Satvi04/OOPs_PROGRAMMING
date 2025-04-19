#include <iostream>
#include <cmath>

using namespace std;

class Loan
{
private:
    int LoanID;
    string ApplicantName;
    double LoanAmount;
    double AnnualInterestRate;
    int TenureMonths;
    double EMI;

public:
    // Default constructor (for testing)
    Loan() {
        LoanID = 0;
        ApplicantName = "Default Applicant";
        LoanAmount = 10000.0;
        AnnualInterestRate = 5.0;
        TenureMonths = 12;
        CalculateEMI();
    }

    // Parameterized constructor (for real customer data)
    Loan(int id, string name, double amount, double rate, int tenure)
    {
        LoanID = id;
        ApplicantName = name;
        LoanAmount = amount;
        AnnualInterestRate = rate;
        TenureMonths = tenure;
        CalculateEMI();
    }

    // Function to calculate EMI
    void CalculateEMI()
    {
        double P = LoanAmount;
        double R = (AnnualInterestRate / 12) / 100;
        int T = TenureMonths;



        if (R == 0)
        {
            EMI = P / T;  // If interest rate is 0, simple division
        }
        else
        {
            double numerator = P * R * pow(1 + R, T);
            double denominator = pow(1 + R, T) - 1;
            EMI = numerator / denominator;
        }
    }

    // Function to display loan details
    void DisplayLoanDetails() const {
        cout << "\n----------------------------------\n";
        cout << "Loan Summary:\n";
        cout << "Loan ID: " << LoanID << "\n";
        cout << "Applicant Name: " << ApplicantName << "\n";
        cout << "Loan Amount: " << LoanAmount << "\n";
        cout << "Annual Interest Rate: " << AnnualInterestRate << "%\n";
        cout << "Tenure: " << TenureMonths << " months\n";
        cout << "Calculated EMI: $" << EMI << "\n";
        cout << "----------------------------------\n";
    }
};

int main() {
    cout << "Welcome to the Loan Management System!\n";

    // Creating a test loan (default values)
    Loan testLoan;
    cout << "\nDisplaying Default Loan Details for Testing:\n";
    testLoan.DisplayLoanDetails();

    // Creating a loan with user input
    int LoanID, TenureMonths;
    string ApplicantName;
    double LoanAmount, InterestRate;

    cout << "\nEnter Loan Details for a New Applicant:\n";
    cout << "Enter Loan ID: ";
    cin >> LoanID;
    cout << "Enter Applicant Name: ";
    cin >> ApplicantName;
    cout << "Enter Loan Amount: ";
    cin >> LoanAmount;
    cout << "Enter Annual Interest Rate (%): ";
    cin >> InterestRate;
    cout << "Enter Tenure (in months): ";
    cin >> TenureMonths;

    // Creating a loan with user-provided data
    Loan customerLoan(LoanID, ApplicantName, LoanAmount, InterestRate, TenureMonths);

    // Displaying customer loan details
    cout << "\nDisplaying Customer Loan Details:\n";
    customerLoan.DisplayLoanDetails();

    cout<<endl<<endl<<"24CE001_Satvi_Akola";

    return 0;
}
