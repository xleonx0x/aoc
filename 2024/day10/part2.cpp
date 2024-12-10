#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';

using namespace std;
using namespace std::chrono;

void DFS(vector<vector<bool>>& visited, vector<vector<int>> graph, ll& ans, int row, int col);

FILE *inputFile;
vector<vector<int>> arr;
vector<int> test;

ll ans = 0;


int main(void) {
    auto start = high_resolution_clock::now();
    // Optimize input and output
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    ifstream inputFile("input.txt");
    string line;

    while (getline(inputFile, line)) {
        vector<int> row;
        for (char num: line) {
            row.push_back((num - '0'));
        }
        arr.push_back(row);
    }


    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
            if (arr[i][j] == 0) {
                DFS(visited, arr, ans, i, j);
            }
        }
    }
    // vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
    // DFS(visited, arr, ans, 0, 0);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    // PRINT(duration.count());
    PRINT(ans);
}

void DFS(vector<vector<bool>>& visited, vector<vector<int>> graph, ll& ans, int row, int col) {

    cout << row << col << '\n';

    visited[row][col] = true;
    if (graph[row][col] == 9) {
        ans++;
        return;
    }

    if (row + 1 < graph.size() && graph[row][col] - graph[row + 1][col] == -1 && !visited[row + 1][col]) {
        DFS(visited, graph, ans, row + 1, col);
    }
    if (row - 1 >= 0 && graph[row][col] - graph[row - 1][col] == -1 && !visited[row - 1][col]) {
        DFS(visited, graph, ans, row - 1, col);
    } 

    if (col + 1 < graph[row].size() && graph[row][col] - graph[row][col + 1] == -1 && !visited[row][col + 1]) {
        DFS(visited, graph, ans, row, col + 1);
    }

    if (col - 1 >= 0 && graph[row][col] - graph[row][col - 1] == -1 && !visited[row][col - 1]) {
        DFS(visited, graph, ans, row, col - 1);
    }
}