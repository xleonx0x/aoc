#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';

using namespace std;

FILE *inputFile;
vector<vector<char>> arr;
vector<char> test;

long long ans = 0;
int hash_c;
int hash_r;

int hash_c1;
int hash_r2;

int main(void) {
    // Optimize input and output
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
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

    vector<vector<int>> hash(arr.size(), vector<int>(arr[0].size(), 0));
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] != '.') {
                int count = 0;
                for (int q = i; q < arr.size(); q++) {
                    for (int k = 0; k < arr[q].size(); k++) {
                        if (count == 0) {
                            k = j + 1;
                        }
                        count++;
                        if (arr[q][k] == arr[i][j]) {
                            hash_r = q - i;
                            if (k < j) {
                                hash_c = j + abs(j - k);
                                hash_c1 = k - abs(j - k);
                            } else if (k > j) {
                                hash_c = j - abs(k - j);
                                hash_c1 = k + abs(k - j);
                            }
                            if (i - hash_r >= 0 && i - hash_r < arr.size() && hash_c >= 0 && hash_c < arr[i - hash_r].size()) {
                                hash[i - hash_r][hash_c] = 1;
                            }
                            if (q + hash_r >= 0 && q + hash_r < arr.size() && hash_c1 >= 0 && hash_c1 < arr[q + hash_r].size()) {
                                hash[q + hash_r][hash_c1] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < hash.size(); i++) {
        for (int j = 0; j < hash[i].size(); j++) {
            if (hash[i][j] == 1) {
                ans++;
            }
        }
    }
    PRINT(ans);
}