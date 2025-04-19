#include<iostream>
using namespace std;

class Product
{
    int ProdID, Quantity;
    float Price;
    char ProdName[20];

public:
    void AddProd()
    {
        cout << "Enter product ID: ";
        cin >> ProdID;
        cout << "Enter name of product: ";
        cin >> ProdName;
        cout << "Enter price of product: ";
        cin >> Price;
        Quantity = 1;

        cout << "Product is added successfully!" << endl;
    }

    int getID()
    {
        return ProdID;
    }

    void UpdateQuan()
    {
        cout << "Enter no. of quantity to be update: ";
        cin >> Quantity;
        cout << "Quantity is updated successfully!" << endl;
    }

    int CalculateValue()
    {
        return Quantity * Price;
    }

    void DisplayBill()
    {
        cout << ProdName << "\t";
        cout << Quantity << "\t\t";
        cout << Price << "\t" << CalculateValue() << endl;
    }
};

int main() //Main function
{
    class Product P[100];
    int Choice;
    int ProdFind;
    int ProdCount = 0;

    //Printing menu
    cout << "Enter 1 to add new product." << endl;
    cout << "Enter 2 to update quantity of product." << endl;
    cout << "Enter 3 to display bill." << endl;
    cout << "Enter 0 to exit." << endl;
    cout << "======================================" << endl;

next:
    cout << "Enter the option which you want: ";
    cin >> Choice;

    switch (Choice) //Switch case
    {
    case 1: //Case for adding new product
    {
        P[ProdCount].AddProd(); //Calling AddProd function
        ProdCount++; //Increment of ProductCount
        break; //Break statement
    }

    case 2: //Case for updating product's quantity
    {
        int ProdFind; //Variable for matching product ID

        cout << "Enter product ID: ";
        cin >> ProdFind;

        for (int i = 0; i < ProdCount; i++)
        {
            if (P[i].getID() == ProdFind) // FIXED: was P[i].ProdID()
            {
                P[i].UpdateQuan();
                break;
            }

            else //If not...
            {
                cout << "Product not found!" << endl;
                break;
            }
        }
        break;
    }

    case 3:
    {
        int TotalValue = 0; //Initializing TotalValue variable to 0

        cout << "--------------------------------------" << endl;
        cout << "Name\tQuantity\tPrice\tTotal" << endl;
    }
    }
}
