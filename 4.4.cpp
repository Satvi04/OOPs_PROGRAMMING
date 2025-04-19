#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class BankingAccount
{
protected:
    int  accNo;
    float accBalance;
    float PreviousBalance;
public:
    BankingAccount(int n, float b)
    {
         accNo = n;
        accBalance = b;
    }
    virtual void Deposit(float Amount, const string& TransactionFile)
    {
        PreviousBalance = accBalance;
        accBalance += Amount;
        ofstream file(TransactionFile, ios::app);
        if (file.is_open())
        {
            file << "Deposited: " << Amount << " | Balance: " << accBalance << endl;
            file.close();
        }
        else
        {
            cout << "Error opening transaction file." << endl;
        }
    }
    virtual void withdraw(float Amount, const string& TransactionFile)
    {
        PreviousBalance = accBalance;
        if (accBalance >= Amount)
        {
            accBalance -= Amount;
            ofstream file(TransactionFile, ios::app);
            if (file.is_open())
            {
                file << "Withdrawn: " << Amount << " | Balance: " << accBalance << endl;
                file.close();
            }
            else
            {
                cout << "Error opening transaction file." << endl;
            }
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }
    void UndoLastTransaction(const string& TransactionFile)
    {
        accBalance = PreviousBalance;
        ofstream file(TransactionFile, ios::app);
        if (file.is_open())
        {
            file << "Transaction undone | Balance: " << accBalance << endl;
            file.close();
        }
        else
        {
            cout << "Error opening transaction file." << endl;
        }
    }
};

class SavingAccount : public BankingAccount
{
    int InterestRate;
public:
    SavingAccount(int num, float bal, int r) : BankingAccount(num, bal)
    {
        InterestRate = r;
    }
    void ApplyInterest(const string& TransactionFile)
    {
        float Interest = (accBalance * InterestRate) / 100;
        accBalance += Interest;
        ofstream file(TransactionFile, ios::app);
        if (file.is_open())
        {
            file << "Applied Interest: " << Interest << " | Balance: " << accBalance << endl;
            file.close();
        }
        else
        {
            cout << "Error opening transaction file." << endl;
        }
    }
};

class CurrentAccount : public BankingAccount
{
    float Limit;
public:
    CurrentAccount(int num, float bal, float lim) : BankingAccount(num, bal)
    {
        Limit = lim;
    }
    void withdraw(float Amount, const string& TransactionFile) override
    {
        PreviousBalance = accBalance;
        if (accBalance + Limit >= Amount)
        {
            accBalance -= Amount;
            ofstream file(TransactionFile, ios::app);
            if (file.is_open())
            {
                file << "Withdrawn: " << Amount << " | Balance: " << accBalance << endl;
                file.close();
            }
            else
            {
                cout << "Error opening transaction file." << endl;
            }
        }
        else
        {
            cout << "Exceeds overdraft Limit." << endl;
        }
    }
};

void ShowTransactionHistory(const string& TransactionFile)
{
    ifstream file(TransactionFile);
    string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No transaction history available." << endl;
    }
}

int main()
{
    int Choice, AccCounter = 0;
    int Number, Rate;
    float Balance, Limit;
    SavingAccount* s = nullptr;
    CurrentAccount* c = nullptr;
    string TransactionFile;

    cout<<"MENU-"<<endl;

    cout << "1  Create saving account\n2  Create current account\n"
         << "3  Deposit to saving account\n4  Withdraw from saving account\n"
         << "5  Deposit to current account\n6  Withdraw from current account\n"
         << "7  See transaction history\n8  Undo last transaction\n9  Exit";

    do
    {
        cout << endl << "Enter your Choice: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            cout << "Enter account Number for saving account: ";
            cin >> Number;
            cout << "Enter initial Balance for saving account: ";
            cin >> Balance;
            cout << "Enter Interest Rate: ";
            cin >> Rate;
            s = new SavingAccount(Number, Balance, Rate);
            TransactionFile = "saving_account_" + to_string(Number) + "_transactions.txt";
            AccCounter++;
            cout<<endl<<"YOUR SAVINGS ACCOUNT HAS BEEN CREATED!"<<endl;
            break;

        case 2:
            cout << "Enter account Number for current account: ";
            cin >> Number;
            cout << "Enter initial Balance for current account: ";
            cin >> Balance;
            cout << "Enter overdraft Limit: ";
            cin >> Limit;
            c = new CurrentAccount(Number, Balance, Limit);
            TransactionFile = "current_account_" + to_string(Number) + "_transactions.txt";
            AccCounter++;
            cout<<endl<<"YOUR CURRENT ACCOUNT HAS BEEN CREATED!"<<endl;

            break;

        case 3:
            if (s)
            {
                float deposit_amount;
                cout << "Enter Deposit Amount: ";
                cin >> deposit_amount;
                s->Deposit(deposit_amount, TransactionFile);
                cout<<endl<<"MONEY DEPOSITED TO SAVINGS ACCOUNT!"<<endl;

            }
            else
            {
                cout << "No saving account created." << endl;
            }
            break;

        case 4:
            if (s)
            {
                float WithdrawAmount;
                cout << "Enter withdraw Amount: ";
                cin >> WithdrawAmount;
                s->withdraw(WithdrawAmount, TransactionFile);
                cout<<endl<<"MONEY WITHDRAWED FROM SAVINGS ACCOUNT!"<<endl;

            }
            else
            {
                cout << "No saving account created." << endl;
            }
            break;

        case 5:
            if (c)
            {
                float deposit_amount;
                cout << "Enter Deposit Amount: ";
                cin >> deposit_amount;
                c->Deposit(deposit_amount, TransactionFile);
                cout<<endl<<"MONEY DEPOSITED TO CURRENT ACCOUNT!"<<endl;

            }
            else
            {
                cout << "No current account created." << endl;
            }
            break;

        case 6:
            if (c)
            {
                float WithdrawAmount;
                cout << "Enter withdraw Amount: ";
                cin >> WithdrawAmount;
                c->withdraw(WithdrawAmount, TransactionFile);
                cout<<endl<<"MONEY WITHDRAWED FROM CURRENT ACCOUNT!"<<endl;

            }
            else
            {
                cout << "No current account created." << endl;
            }
            break;

        case 7:
            ShowTransactionHistory(TransactionFile);
            break;

        case 8:
            if (s)
            {
                s->UndoLastTransaction(TransactionFile);
            }
            else if (c)
            {
                c->UndoLastTransaction(TransactionFile);
            }
            else
            {
                cout << "No account created." << endl;
            }
            break;

        case 9:
            cout << "Exiting system." << endl;
            break;

        default:
            cout << "Invalid Choice." << endl;
            break;
        }
    }
    while (Choice != 9);

    delete s;
    delete c;

    cout<<endl<<"24CE001_Satvi_Akola"<<endl;
}
