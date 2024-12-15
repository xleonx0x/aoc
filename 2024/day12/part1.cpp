#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';

using namespace std;

FILE *inputFile;
vector<vector<char>> arr;

ll ans = 0;

void DFS(vector<vector<bool>>& visited, vector<vector<char>> arr, int i, int j, ll& side, ll& area) {
    if (visited[i][j]) {
        return;
    }
    visited[i][j] = true;

    area++;
    bool row_1 = i + 1 >= arr.size();
    bool row_2 = i - 1 < 0;
    bool col_1 = j - 1 < 0;
    bool col_2 = j + 1 >= arr[i].size();
    int dec = 0;
    if (row_1 || arr[i + 1][j] != arr[i][j]) {
        dec++;
    }

    if (row_2 || arr[i - 1][j] != arr[i][j]) {
        dec++;
    }

    if (col_1 || arr[i][j - 1] != arr[i][j]) {
        dec++;
    }

    if (col_2 || arr[i][j + 1] != arr[i][j]) {
        // printf("%c and %c %d\n", arr[i][j + 1], arr[i][j], col_2);
        dec++;
    }
    side += dec;
    printf("[%d][%d] has %d sides\n", i, j, dec);
    // exit(0);
    if (!row_1 && !visited[i + 1][j] && arr[i][j] == arr[i + 1][j]) {
        DFS(visited, arr, i + 1, j, side, area);
    }

    if (!row_2 && !visited[i - 1][j] && arr[i][j] == arr[i - 1][j]) {
        DFS(visited, arr, i - 1, j , side, area);
    }

    if (!col_1 && !visited[i][j - 1] && arr[i][j] == arr[i][j - 1]) {
        DFS(visited, arr, i, j - 1, side, area);
    }

    if (!col_2 && !visited[i][j + 1] && arr[i][j] == arr[i][j + 1]) {
        DFS(visited, arr, i, j + 1, side, area);
    }
}

int main(void) {

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

    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
    ll side = 0;
    ll area = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            side = 0;
            area = 0;
            if (!visited[i][j]) {
                DFS(visited, arr, i, j, side, area);
            }
            // printf()
            PRINT(side);
            PRINT(area);
            ans += side * area;
        }
    }

    PRINT(ans);
}


