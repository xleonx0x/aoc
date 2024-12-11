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
    while (ss >> num) {
        arr.push_back(num);
    }

    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                arr[i] = 1;
            } else if (to_string(arr[i]).length() % 2 == 0) {
                int length = to_string(arr[i]).length();
                ll first_half = stoll(to_string(arr[i]).substr(0, length / 2));
                ll second_half = stoll(to_string(arr[i]).substr(length / 2, length));
                printf("splitgin %d into %d and %d\n", arr[i], first_half, second_half);
                arr[i] = first_half;
                arr.insert(arr.begin() + i + 1, second_half);

                i++;
            } else {
                arr[i] *= 2024;
            }
        }
    }

    for (auto num: arr) {
        printf("%lld ", num);
    }
    printf("\n");
    

    PRINT(arr.size());
}