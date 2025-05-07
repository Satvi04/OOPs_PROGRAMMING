#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string* transactions;
    int transactionCount;

    void logTransaction(const string& log) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = log;
        } else {
            cout << "Transaction log full. Unable to log further operations.\n";
        }
    }

public:
    // Constructor to initialize the account holder and balance
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
        transactions = new string[MAX_TRANSACTIONS]; // Allocate memory for transaction logs
        transactionCount = 0; // Initialize transaction count to 0
    }

    // Destructor to release allocated memory
    ~BankAccount() {
        delete[] transactions;
    }

    // Method to deposit an amount
    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        logTransaction("Deposited: ₹" + to_string(amount));
    }

    // Method to withdraw an amount
    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient balance.");
        }
        balance -= amount;
        logTransaction("Withdrew: ₹" + to_string(amount));
    }

    // Method to display the current balance
    void displayBalance() const {
        cout << "Current Balance: ₹" << balance << endl;
    }

    // Method to display the transaction history
    void showTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; i++) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }
};

int main() {
    string name;
    double initialBalance;

    // Get user input for account holder name and initial balance
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial balance: ₹";
    cin >> initialBalance;

    // Create a bank account for the user
    BankAccount account(name, initialBalance);

    // Perform transactions based on user input
    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Transaction History\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter deposit amount: ₹";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 2:
                    cout << "Enter withdrawal amount: ₹";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 3:
                    account.displayBalance();
                    break;
                case 4:
                    account.showTransactionHistory();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 5);



    return 0;
}
