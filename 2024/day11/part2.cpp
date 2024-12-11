#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';

using namespace std;

FILE *inputFile;
vector<ll> arr;

ll ans = 0;


int main(void) {

    // cin.tie(nullptr);
    // cin.sync_with_stdio(false);
    
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


    getline(inputFile, line);
    stringstream ss(line);
    ll num;

    map<ll, ll> test;
    map<ll, ll> map;

    while (ss >> num) {
        test[num] += 1;
    }
    ans = test.size();
    for (int j = 0; j < 75; j++) {
        map.clear();
        for (auto num: test) {
            // cout << num.first << '\n';
            if (num.first == 0) {
                map[1] += num.second;
            } else if (to_string(num.first).length() % 2 == 0) {
                ll length = to_string(num.first).length();
                ll first_half = stoll(to_string(num.first).substr(0, length / 2));
                ll second_half = stoll(to_string(num.first).substr(length / 2, length));
                map[first_half] += num.second;
                map[second_half] += num.second;
                ans += num.second;
            } else {
                map[num.first * 2024] += num.second;
            }
        }
        test.clear();
        for (auto change : map) {
            test[change.first] = change.second;
        }
    }

    for (auto num: test) {
        for (int i = 0; i < num.second; i++ ) {
            printf("%d ", num.second);
        }
    }
    PRINT('\n');
    
    

    PRINT(ans);
}