#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool compareScores(const pair<string, int>& student1, const pair<string, int>& student2) {
    return student1.second > student2.second;
}

int main() {
    vector<pair<string, int>> students;
    int n;
    string name;
    int score;


    cout << "Enter the number of students: ";
    cin >> n;


    cout << "Enter student name and score:\n";
    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        students.push_back(make_pair(name, score));
    }


    sort(students.begin(), students.end(), compareScores);


    cout << "\nRanked List of Students (Highest Score First):\n";
    int rank = 1;
    for (vector<pair<string, int>>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << "Rank " << rank << ": " << it->first << " - Score: " << it->second << endl;
        ++rank;
    }

    return 0;
}
