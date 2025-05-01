#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "PLEASE ENTER THE  VAILD OUTPUT '" << filename << "'" << endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length() + 1;

        bool inWord = false;
        for (char ch : line) {
            if (ch == ' ' || ch == '\t') {
                inWord = false;
            } else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }
    }


    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    return 0;
}
