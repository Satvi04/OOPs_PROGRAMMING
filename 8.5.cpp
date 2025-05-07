#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    map<string, vector<string>> DirectoryMap;
    int Choice;
    string FolderName, FileName;

    while (true)
    {
        cout << "\n1. Create Folder\n2. Add File to Folder\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> Choice;
        cin.ignore(); // Clear newline character after inputswitch (Choice)
        {
            switch (Choice)
            {
            case 1:
            {
                cout << "Enter folder name: ";
                getline(cin, FolderName);
                if (DirectoryMap.count(FolderName) == 0)
                {
                    DirectoryMap[FolderName] = {}; // Create folder
                    cout << "Folder created." << endl;
                }
                else
                {
                    cout << "Folder already exists." << endl;
                }
                break;
            }
            case 2:
            {
                cout << "Enter folder name: ";
                getline(cin, FolderName);
                if (DirectoryMap.count(FolderName) == 0)
                {
                    cout << "Folder doesn't exist." << endl;
                }
                else
                {
                    cout << "Enter file name: ";
                    getline(cin, FileName);
                    DirectoryMap[FolderName].push_back(FileName);
                    cout << "File added to folder." << endl;
                }
                break;
            }
            case 3:
            {
                cout << endl
                     << "--- Directory Structure ---" << endl;
                map<string, vector<string>>::iterator It;
                for (It = DirectoryMap.begin(); It != DirectoryMap.end(); ++It)
                {
                    cout << It->first << endl; // Folder name
                    vector<string> &FileList = It->second;
                    for (int i = 0; i < FileList.size(); ++i)
                    {
                        cout << "  " << FileList[i] << endl; // Indented file name
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}
