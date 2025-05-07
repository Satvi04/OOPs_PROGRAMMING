#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isDuplicate(const vector<int>& vec, int value) {

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> transactionIDs;
    int n, transactionID;


    cout << "Enter the number of transaction IDs: ";
    cin >> n;


    cout << "Enter " << n << " transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> transactionID;

        if (!isDuplicate(transactionIDs, transactionID)) {
            transactionIDs.push_back(transactionID);
        }
    }


    sort(transactionIDs.begin(), transactionIDs.end());


    cout << "\nUnique transaction IDs in sorted order:\n";
    for (int i = 0; i < transactionIDs.size(); ++i) {
        cout << transactionIDs[i] << " ";
    }
    cout << endl;

    return 0;
}
