
#include <bits/stdc++.h>

using namespace std;

FILE *inputFile;
vector<vector<long long>> arr;
vector<long long> test;

long long ans = 0;

int main(void) {
    ifstream inputFile("input.txt");
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<long long> row;

        string part;
        getline(iss, part, ':');
        long long beforeColon = stoll(part);
        while (iss >> part) {
            row.push_back(stoi(part));                
        }

        test.push_back(beforeColon);
        arr.push_back(row);
    }

    for (int i = 0; i < arr.size(); i++) {
        int n = arr[i].size() - 1;
        int totalCombinations = pow(3, n); 
        vector<vector<int>> combinations;

        for (int i = 0; i < totalCombinations; ++i) {
            vector<int> combination;
            int num = i;
            for (int j = 0; j < n; ++j) {
                combination.push_back(num % 3);
                num /= 3;
            }
            combinations.push_back(combination);
        }
   
        for (int q = 0; q < combinations.size(); q++) {
            long long val = arr[i][0];
            string combine = "";
            for (int j = 0; j < arr[i].size() - 1; j++) {
                if (combinations[q][j] == 0) {
                    val += arr[i][j + 1]; 
                } else if (combinations[q][j] == 1) {
                    val *= arr[i][j + 1];
                } else if (combinations[q][j] == 2) {
                    combine = to_string(val) + to_string(arr[i][j + 1]);
                    val = stoll(combine);
                }
            }
            if (val == test[i]) {
                ans += val;
                break;
            }
        }
    }
    

    cout << ans << '\n';

}