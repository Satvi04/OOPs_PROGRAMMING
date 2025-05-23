#include<iostream>
using namespace std;

class Bank
{
private:
    string accHolder;
    int accNo;
    double Balance, dep, WithdramAmount;

public:
    void getData()
    {
        cout << endl << "Enter account holder name: ";
        cin >> accHolder;
        cout << endl << "Enter account number: ";
        cin >> accNo;
        cout << endl << "Enter initial Balance: ";
        cin >> Balance;
    }

    int getAcc()
    {
        return accNo;
    }

    void DisplayAcc()
    {
        cout << endl << "---------------------------------------------------------------------------";
        cout << endl << "NAME: " << accHolder;
        cout << endl << "ACC_NO: " << accNo;
        cout << endl << "Balance: " << CurrentBalance();
    }

    void Deposit()
    {
        cout << endl << "Enter how much money you want to deposit: ";
        cin >> dep;
        Balance += dep;
        cout << endl << "You have deposited money successfully.";
    }

    double CurrentBalance()
    {
        return Balance;
    }

    void withdraw()
    {
        cout << endl << "Enter amount you want to withdraw: ";
        cin >> WithdramAmount;

        if (WithdramAmount > Balance)
        {
            cout << endl << "You can't withdraw this much amount since you don't have sufficient Balance.";
        }
        else
        {
            Balance -= WithdramAmount;
            cout << endl << "You have withdrawn money successfully.";
        }
    }

};

int main()
{
    Bank BankArray[100];
    int AccFinds;
    int choice;
    int numAcc = 0;

    cout << "Enter 1 to add account details." << endl;
    cout << "Enter 2 to deposit." << endl;
    cout << "Enter 3 to withdraw." << endl;
    cout << "Enter 4 to display current Balance." << endl;
    cout << "Else 5 to Exit." << endl;
    cout << "===================================" << endl;

    while (true)
    {
        cout << endl << "Enter your choice: ";
        cin >> choice;

        bool found = false;
        switch (choice)
        {
        case 1:
        {
            BankArray[numAcc].getData();
            numAcc++;
            break;
        }

        case 2:
        {
            cout << "Enter the account number: ";
            cin >> AccFinds;

            for (int i = 0; i < numAcc; i++)
            {
                if (BankArray[i].getAcc() == AccFinds)
                {
                    BankArray[i].Deposit();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "Enter the account number: ";
            cin >> AccFinds;

            for (int i = 0; i < numAcc; i++)
            {
                if (BankArray[i].getAcc() == AccFinds)
                {
                    BankArray[i].withdraw();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }
            break;
        }

        case 4:
        {
            cout << "Enter the account number: ";
            cin >> AccFinds;

            for (int i = 0; i < numAcc; i++)
            {
                if (BankArray[i].getAcc() == AccFinds)
                {
                    BankArray[i].DisplayAcc();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account not found!" << endl;
            }
            break;
        }

        case 5:
        {
            return 0;
        }

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    cout << "24CE001_Satvi_Akola" << endl;
}
