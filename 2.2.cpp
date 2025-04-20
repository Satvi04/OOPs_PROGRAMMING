#include<iostream>
using namespace std;

class Product {
    int ProdID, Quantity;
    float Price;
    char ProdName[20];

public:
    void AddProd() {
        cout << "Enter product ID: ";
        cin >> ProdID;
        cout << "Enter name of product: ";
        cin >> ProdName;
        cout << "Enter price of product: ";
        cin >> Price;
        Quantity = 1;
        cout << "Product is added successfully!" << endl;
    }

    int getID() {
        return ProdID;
    }

    void UpdateQuan() {
        cout << "Enter no. of quantity to be update: ";
        cin >> Quantity;
        cout << "Quantity is updated successfully!" << endl;
    }

    float CalculateValue() {
        return Quantity * Price;
    }

    void DisplayBill() {
        cout << ProdName << "\t" << Quantity << "\t\t" << Price << "\t" << CalculateValue() << endl;
    }
};

int main() {
    Product P[100];
    int Choice;
    int ProdCount = 0;

    cout << "Enter 1 to add new product." << endl;
    cout << "Enter 2 to update quantity of product." << endl;
    cout << "Enter 3 to display bill." << endl;
    cout << "Enter 0 to exit." << endl;
    cout << "======================================" << endl;

    while (true) {
        cout << "Enter the option which you want: ";
        cin >> Choice;

        switch (Choice) {
        case 1: {
            P[ProdCount].AddProd();
            ProdCount++;
            break;
        }

        case 2: {
            int ProdFind;
            cout << "Enter product ID: ";
            cin >> ProdFind;

            bool found = false;
            for (int i = 0; i < ProdCount; i++) {
                if (P[i].getID() == ProdFind) {
                    P[i].UpdateQuan();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found!" << endl;
            }
            break;
        }

        case 3: {
            float TotalValue = 0;
            cout << "--------------------------------------" << endl;
            cout << "Name\tQuantity\tPrice\tTotal" << endl;
            cout << "--------------------------------------" << endl;
            for (int i = 0; i < ProdCount; i++) {
                P[i].DisplayBill();
                TotalValue += P[i].CalculateValue();
            }
            cout << "--------------------------------------" << endl;
            cout << "TOTAL VALUE = " << TotalValue << endl;
            cout << "--------------------------------------" << endl;
            break;
        }

        case 0: {
            return 0;
        }

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
