#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string accHolder;
    int accNo;
    double balance;
    static int totalAccounts;

public:
    void addAccount();
    int getAccNumber();
    string getAccHolder();
    double getBalance();
    void depositMoney(double amount);
    void withdrawMoney(double amount);
    void displayAccount();

    static int getTotalAccounts() {
        return totalAccounts;
    }

    static void transfer(BankAccount& from, BankAccount& to, double amount) {
        if (amount > 0 && amount <= from.balance) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Amount transferred successfully!" << endl;
            cout << "New balance of " << from.accHolder << " is: " << from.balance << endl;
            cout << "New balance of " << to.accHolder << " is: " << to.balance << endl;
        } else {
            cout << "Insufficient amount or invalid input. Try again." << endl;
        }
    }
};

int BankAccount::totalAccounts = 0;

void BankAccount::addAccount() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Enter Account Holder Name: ";
    cin >> accHolder;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    totalAccounts++;
    cout << "Bank account created successfully!" << endl;
}

int BankAccount::getAccNumber() {
    return accNo;
}

string BankAccount::getAccHolder() {
    return accHolder;
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::depositMoney(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Amount deposited successfully!" << endl;
        cout << "New balance is: " << balance << endl;
    } else {
        cout << "Invalid amount. Try again." << endl;
    }
}

void BankAccount::withdrawMoney(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Amount withdrawn successfully!" << endl;
        cout << "New balance is: " << balance << endl;
    } else {
        cout << "Insufficient balance or invalid amount." << endl;
    }
}

void BankAccount::displayAccount() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Account Holder Name: " << accHolder << endl;
    cout << "Account Number: " << accNo << endl;
    cout << "Account Balance: " << balance << endl;
}

int main() {
    BankAccount accounts[100];
    int n = 0, choice;
    double amount;

    while (true) {
        cout << "\n----------- Bank Account Services -----------" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Transfer Money" << endl;
        cout << "6. Exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int accNo;

        switch (choice) {
        case 1:
            cout << "Enter number of accounts to add: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                accounts[i].addAccount();
            }
            break;

        case 2:
            cout << "Enter the account number to deposit into: ";
            cin >> accNo;
            for (int i = 0; i < n; i++) {
                if (accounts[i].getAccNumber() == accNo) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[i].depositMoney(amount);
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter the account number to withdraw from: ";
            cin >> accNo;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            for (int i = 0; i < n; i++) {
                if (accounts[i].getAccNumber() == accNo) {
                    accounts[i].withdrawMoney(amount);
                    break;
                }
            }
            break;

        case 4:
            cout << "Enter the account number to display: ";
            cin >> accNo;
            for (int i = 0; i < n; i++) {
                if (accounts[i].getAccNumber() == accNo) {
                    accounts[i].displayAccount();
                    break;
                }
            }
            break;

        case 5: {
            int accFrom, accTo;
            cout << "Enter sender's account number: ";
            cin >> accFrom;
            cout << "Enter receiver's account number: ";
            cin >> accTo;
            cout << "Enter amount to transfer: ";
            cin >> amount;
            bool foundFrom = false, foundTo = false;
            int iFrom, iTo;

            for (int i = 0; i < n; i++) {
                if (accounts[i].getAccNumber() == accFrom) {
                    foundFrom = true;
                    iFrom = i;
                }
                if (accounts[i].getAccNumber() == accTo) {
                    foundTo = true;
                    iTo = i;
                }
            }

            if (foundFrom && foundTo) {
                BankAccount::transfer(accounts[iFrom], accounts[iTo], amount);
            } else {
                cout << "One or both account numbers not found!" << endl;
            }
            break;
        }

        case 6:
            cout << "Thank you for using our service!" << endl;
            cout << "24CE001_Satvi_Akola" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}