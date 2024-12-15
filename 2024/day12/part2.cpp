#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';

using namespace std;

FILE *inputFile;
vector<vector<char>> arr;

ll ans = 0;

void DFS(vector<vector<bool>>& visited, vector<vector<bool>>& visited_no_save, vector<vector<char>> arr, int i, int j, ll& side, ll& area) {
    if (visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    visited_no_save[i][j] = true;

    area++;
    bool row_1 = i + 1 >= arr.size();
    bool row_2 = i - 1 < 0;
    bool col_1 = j - 1 < 0;
    bool col_2 = j + 1 >= arr[i].size();

    if (!row_1 && !visited[i + 1][j] && arr[i][j] == arr[i + 1][j]) {
        DFS(visited, visited_no_save, arr, i + 1, j, side, area);
    }

    if (!row_2 && !visited[i - 1][j] && arr[i][j] == arr[i - 1][j]) {
        DFS(visited, visited_no_save, arr, i - 1, j , side, area);
    }

    if (!col_1 && !visited[i][j - 1] && arr[i][j] == arr[i][j - 1]) {
        DFS(visited, visited_no_save, arr, i, j - 1, side, area);
    }

    if (!col_2 && !visited[i][j + 1] && arr[i][j] == arr[i][j + 1]) {
        DFS(visited, visited_no_save, arr, i, j + 1, side, area);
    }
}

int main(void) {

    // cin.tie(nullptr);
    // cin.sync_with_stdio(false);
    
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

    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
    ll side = 0;
    ll area = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            side = 0;
            area = 0;
            map<pair<int, int>, int> left;
            map<pair<int, int>, int> right;
            map<pair<int, int>, int> top;
            map<pair<int, int>, int> bot;
            vector<vector<bool>> visited_no_save(arr.size(), vector<bool>(arr[0].size(), false));
            if (!visited[i][j]) {
                DFS(visited, visited_no_save, arr, i, j, side, area);
                for (ll k = 0; k < visited_no_save.size(); k++) {
                    for (ll q = 0; q < visited_no_save[k].size(); q++) {
                        if (visited[k][q]) {
                            if (k - 1 < 0 || !visited_no_save[k - 1][q]) {
                                top[{k, q}] = 1;
                            }
                            if (k + 1 >= visited_no_save.size() || !visited_no_save[k + 1][q]) {
                                bot[{k, q}] = 1;
                            }
                            if (q - 1 < 0 || !visited_no_save[k][q - 1]) {
                                left[{k, q}] = 1;
                            }
                            if (q + 1 >= visited_no_save[k].size() || visited_no_save[k][q + 1]) {
                                right[{k, q}] = 1;
                            }
                        }
                    }
                }
                
            }
            ans += side * area;
       
        }
    }

    PRINT(ans);
}


