
#include <iostream>

using namespace std;

class Account
{
private:
    string accHolder;
    int accNo;
    double Balance;

public:
    // Constructor with no initial Balance
    Account(string name, int accNumber)
    {
        accHolder = name;
        accNo = accNumber;
        Balance = 0.0;  // Default Balance is 0
    }

    // Constructor with an initial Balance
    Account(string name, int accNumber, double initialBalance)
    {
        accHolder = name;
        accNo = accNumber;
        Balance = initialBalance;
    }

    // Deposit money into account
    void Deposit(double Amount)

    {
        if (Amount > 0)
        {
            Balance += Amount;
            cout << "Successfully Deposited ₹" << Amount << " into account " << accNo << ".\n";
        }

        else

        {
            cout << "Invalid Deposit Amount. Please enter a positive Amount.\n";
        }
    }



    // Withdraw money from account with Balance check
    void withdraw(double Amount)
    {
        if (Amount > 0 && Amount <= Balance)
        {
            Balance -= Amount;
            cout << "Successfully withdrawn " << Amount << " from account " << accNo << ".\n";
        }
        else if (Amount > Balance)
        {
            cout << "Insufficient funds! Withdrawal failed.\n";
        }
        else
        {
            cout << "Invalid withdrawal Amount.\n";
        }
    }

    // Display account details
    void displayAccountSummary() const
    {
        cout << "\n----------------------------------\n";
        cout << "Account Summary:\n";
        cout << "Account Holder: " << accHolder << "\n";
        cout << "Account Number: " << accNo << "\n";
        cout << "Balance: $" << Balance << "\n";
        cout << "----------------------------------\n";
    }

    // Get account number
    int getaccNo() const
    {
        return accNo;
    }
};

int main()
{
    cout << "Welcome to the Bank Account Management System!\n";

    // Creating two accounts
    char name1[50], name2[50];
    int accNumber1, accNumber2;
    double initialBalance;

    cout << "\nEnter details for Account 1 (No initial Balance required):\n";
    cout << "Enter Account Holder Name: ";
    cin >> name1;
    cout << "Enter Account Number: ";
    cin >> accNumber1;

    cout << "\nEnter details for Account 2 (With initial Balance):\n";
    cout << "Enter Account Holder Name: ";
    cin >> name2;
    cout << "Enter Account Number: ";
    cin >> accNumber2;
    cout << "Enter Initial Balance: $";
    cin >> initialBalance;

    // Creating the accounts
    Account account1(name1, accNumber1);
    Account account2(name2, accNumber2, initialBalance);

    // Menu for transactions
    int choice, accNumber;
    double Amount;

    do
    {
        cout << "\nBanking System Menu:\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display Account Summary\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            cout << "Enter Account Number: ";
            cin >> accNumber;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter Amount to Deposit: $";
            cin >> Amount;
            if (accNumber == account1.getaccNo())
            {
                account1.Deposit(Amount);
            }
            else if (accNumber == account2.getaccNo())
            {
                account2.Deposit(Amount);
            }
            else
            {
                cout << "Invalid Account Number!\n";
            }
            break;

        case 2:
            cout << "Enter Amount to withdraw: $";
            cin >> Amount;
            if (accNumber == account1.getaccNo())
            {
                account1.withdraw(Amount);
            }
            else if (accNumber == account2.getaccNo())
            {
                account2.withdraw(Amount);
            }
            else
            {
                cout << "Invalid Account Number!\n";
            }
            break;

        case 3:
            if (accNumber == account1.getaccNo())
            {
                account1.displayAccountSummary();
            }
            else if (accNumber == account2.getaccNo())
            {
                account2.displayAccountSummary();
            }
            else
            {
                cout << "Invalid Account Number!\n";
            }
            break;

        case 4:
            cout << "Exiting program... Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
    while (choice != 4);


    cout<<endl<<endl<<"24CE001_Satvi_Akola";


    return 0;
}


