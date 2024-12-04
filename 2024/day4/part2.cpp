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
            if (i + 2 < arr.size() && j + 2 < arr[i + 2].size()) {
                for (int k = j, q = i, counter = 0; counter < 3; q++, k++, counter++) {
                    line += arr[q][k];
                }
                for (int k = j, q = i + 2, counter = 0; counter < 3; q--, k++, counter++) {
                    line += arr[q][k];
                }
                if (line.compare("MASMAS") == 0 || line.compare("SAMMAS") == 0 || line.compare("MASSAM") == 0 || line.compare("SAMSAM") == 0) {
                    ans++;
                }
            }
            
        }
    }
    cout << ans << '\n';
}
