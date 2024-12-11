#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';
#define int long long

using namespace std;

FILE *inputFile;
vector<vector<char>> arr;

ll ans = 0;

int main(void) {

    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    ifstream inputFile("input.txt");
    string line;

    // 2d chars
    // while (getline(inputFile, line)) {
    //     istringstream iss(line);
    //     vector<char> row;
    //     char character;
    //     while (iss >> character) {
    //         row.push_back(character);                
    //     }
    //     arr.push_back(row);
    // }

    // 1d ints
    // getline(inputFile, line);
    // stringstream ss(line);
    // ll num;
    // while (ss >> num) {
    //     arr.push_back(num);
    // }

    // 2d ints (single digits)
    // while (getline(inputFile, line)) {
    //     vector<int> row;
    //     for (char num: line) {
    //         row.push_back((num - '0'));
    //     }
    //     arr.push_back(row);
    // }

    PRINT(ans);
}