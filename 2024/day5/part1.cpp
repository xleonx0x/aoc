
#include <bits/stdc++.h>

using namespace std;

FILE *inputFile;
vector<vector<int>> pages;
vector<vector<int>> rules;

int ans = 0;

int main(void) {
    ifstream inputFile("pages.txt");
    ifstream inputFileRules("rules.txt");
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> row;
        string part;
        while (getline(iss, part, ',')) {
            row.push_back(stoi(part));
        }

        pages.push_back(row);
    }
    
    while (getline(inputFileRules, line)) {
        istringstream iss(line);
        vector<int> row;
        string part;

        while (getline(iss, part, '|')) {
            row.push_back(stoi(part));
        }

        rules.push_back(row);
    }

    bool invalid = false;
    for (int i = 0; i < pages.size(); i++) {
        invalid = false;
        for (int j = 0; j < pages[i].size(); j++) {
            for (int k = 0; k < rules.size(); k++) {
                if (rules[k][1] == pages[i][j]) {
                    for (int q = j; q < pages[i].size(); q++) {
                        if (pages[i][q] == rules[k][0]) {
                            invalid = true;
                        }
                    }
                }
            }
            
        }
        if (invalid == false) {
            int mid = pages[i].size() / 2;
            ans += pages[i][mid];
        }
    }

    cout << ans << '\n';
}