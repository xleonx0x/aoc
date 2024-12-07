
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
        int totalCombinations = 1 << n; 
        vector<vector<long long>> combinations;

        for (int i = 0; i < totalCombinations; ++i) {
            vector<long long> combination;
            for (int j = n - 1; j >= 0; --j) {
                combination.push_back((i >> j) & 1);
            }
            combinations.push_back(combination);
        }
   
        for (int q = 0; q < combinations.size(); q++) {
            long long val = arr[i][0];
            for (int j = 0; j < arr[i].size() - 1; j++) {
                // cout << combinations[q][j] << '\n';
                if (combinations[q][j] == 0) {
                    val += arr[i][j + 1]; 
                } else if (combinations[q][j] == 1) {
                    val *= arr[i][j + 1];
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