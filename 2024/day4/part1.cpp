
#include <bits/stdc++.h>

using namespace std;

FILE *inputFile;
vector<vector<char>> arr;

int ans = 0;

int main(void) {
    ifstream inputFile("input.txt");
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<char> row;
        char character;
        while (iss >> character) {
            row.push_back(character);                
        }
        arr.push_back(row);
    }

    
    for (int i = 0; i < arr.size(); i++) {
        line = "";
        for (int j = 0; j < arr[i].size(); j++) {
            line = "";
            if (j + 3 < arr[i].size()) {
                for (int k = j, counter = 0; counter < 4; k++, counter++) {
                    line += arr[i][k];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (j - 3 >= 0) {
                for (int k = j, counter = 0; counter < 4; k--, counter++) {
                    line += arr[i][k];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (i + 3 < arr.size()) {
                for (int k = i, counter = 0; counter < 4; k++, counter++) {
                    line += arr[k][j];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (i - 3 >= 0) {
                for (int k = i, counter = 0; counter < 4; k--, counter++) {
                    line += arr[k][j];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (i + 3 < arr.size() && j + 3 < arr[i + 3].size()) {
                for (int k = i, q = j, counter = 0; counter < 4; k++, q++, counter++) {
                    line += arr[k][q];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (i + 3 < arr.size() && j - 3 < arr[i + 3].size()) {
                for (int k = i, q = j, counter = 0; counter < 4; k++, q--, counter++) {
                    line += arr[k][q];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (i - 3 >= 0 && j - 3 < arr[i - 3].size()) {
                for (int k = i, q = j, counter = 0; counter < 4; k--, q--, counter++) {
                    line += arr[k][q];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
            line = "";
            if (i - 3 >= 0 && j + 3 < arr[i - 3].size()) {
                for (int k = i, q = j, counter = 0; counter < 4; k--, q++, counter++) {
                    line += arr[k][q];
                }
                if (line.compare("XMAS") == 0) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}