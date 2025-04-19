#include<iostream>
using namespace std;

class Inventory
{
    int ItemID;
    char ItemName[20];
    float Price;
    int Quantity;

public:

    void AddItemDetails()
    {
        cout << "Enter item ID: ";
        cin >> ItemID;
        cout << "Enter item's name: ";
        cin >> ItemName;
        cout << "Enter price of item: ";
        cin >> Price;

        Quantity = 1;
    }

    int getItemID()
    {
        return ItemID;
    }

    void IncreaseItemQuan()
    {
        int NewQuantity;
        cout << "Enter quantity to be increased: ";
        cin >> NewQuantity;

        Quantity+=NewQuantity;

        cout << "Item's Quantity is successfully increased!" << endl;
    }

    void DecreaseItemQuan()
    {
        int NewQuantity;
        cout << "Enter quantity to be decreased: ";
        cin >> NewQuantity;

        if(Quantity >= NewQuantity)
        {
            Quantity-=NewQuantity;

            cout << "Item's Quantity is successfully decreased!" << endl;
        }

        else
        {
            cout << "Insufficient quantity!" << endl;
        }
    }

    void DisplayItemDetails()
    {
        cout << "Item's details:" << endl;
        cout << "ID: " << ItemID << endl;
        cout << "Name: " << ItemName << endl;
        cout << "Price: " << Price << endl;
        cout << "Quantity: " << Quantity << endl;
    }
};

int main()
{
    class Inventory I[100];
    int NumItem = 0;
    int ItemFind,Choice;

    cout << "Enter 1 to add item." << endl;
    cout << "Enter 2 to increase quantity." << endl;
    cout << "Enter 3 to decrease quantity." << endl;
    cout << "Enter 4 to display item's details." << endl;
    cout << "Enter 5 to Exit." << endl;
    cout << "==================================" << endl;

next :
    cout << "Enter the option which you want: ";
    cin >> Choice;

    switch(Choice)
    {
    case 1:
    {
        I[NumItem].AddItemDetails();
        NumItem++;

        break;
    }

    case 2:
    {
        cout << "Enter item ID: ";
        cin >> ItemFind;

        for (int i = 0; i <= NumItem; i++)
        {
            if (I[i].getItemID() == ItemFind)
            {
                I[i].IncreaseItemQuan();
                break;
            }

            else
            {
                cout << "Item not found!" << endl;
                break;
            }
        }
        break;
    }

    case 3:
    {
        cout << "Enter item ID: ";
        cin >> ItemFind;

        for (int i = 0; i <= NumItem; i++)
        {
            if (I[i].getItemID() == ItemFind)
            {
                I[i].DecreaseItemQuan();
                break;
            }

            else
            {
                cout << "Item not found!" << endl;
                break;
            }
        }
        break;
    }

    case 4:
    {
        cout << "Enter item ID: ";
        cin >> ItemFind;

        for (int i = 0; i <= NumItem; i++)
        {
            if (I[i].getItemID() == ItemFind)
            {
                I[i].DisplayItemDetails();
                break;
            }

            else
            {
                cout << "Item not found!" << endl;
                break;
            }
        }
        break;
    }

    case 5:
    {
        cout << "24CE132_Satvi_Akola" << endl;
        return 0;
    }
    }
    goto next;
}
