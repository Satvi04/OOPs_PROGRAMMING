#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("data.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string data;
    int charCount = 0;

    cout << "Enter data : " << endl;

    while (true) {
        getline(cin, data);
        if (data == "exit")
            break;


        cout << "You entered: " << data << endl;


        file << data << endl;


        charCount += data.length();
        cout << "Total characters so far: " << charCount << endl;
    }

    file.close();
    cout << "Data stored in file successfully!" << endl;

    return 0;
}
