
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

    int x;
    int y;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == '^' || arr[i][j] == '<' || arr[i][j] == 'v' || arr[i][j] == '>') {
                x = i;
                y = j;
                break;
            }
        }
    }

    int original_x = x;
    int original_y = y;
    char original_dir = arr[x][y];
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            bool hash = false;
            if (arr[i][j] != '^' && arr[i][j] != '<' && arr[i][j] != 'v' && arr[i][j] != '>' && arr[i][j] != '#') {
                arr[i][j] = '#';
                hash = true;
            }
            x = original_x;
            y = original_y;
            arr[x][y] = original_dir;
            int steps = 0;
            while (x >= 0 && x < arr.size() && y >= 0 && y < arr[x].size()) {
                steps++;
                if (steps > 20000) {
                    ans++;
                    break;
                }
                if (arr[x][y] == '^') {
                    if (x - 1 >= 0 &&  arr[x - 1][y] == '#' ) {
                        arr[x][y] = '>';
                        continue;
                    }
                    arr[x][y] = '.';
                    if (x - 1 < 0) break;
                    x--;
                    arr[x][y] = '^';
                } else if (arr[x][y] == 'v') {
                    if (x + 1 < arr.size() && arr[x + 1][y] == '#'  ) {
                        arr[x][y] = '<';
                        continue;
                    }
                    arr[x][y] = '.';
                    if (x + 1 >= arr.size()) break;
                    x++;
                    arr[x][y] = 'v';
                } else if (arr[x][y] == '>') {
                    if (y + 1 < arr[x].size() && arr[x][y + 1] == '#') {
                        arr[x][y] = 'v';
                        continue;
                    }
                    arr[x][y] = '.';
                    if (y + 1 >= arr[x].size()) break;
                    y++;
                    arr[x][y] = '>';
                } else if (arr[x][y] == '<') {
                    if ( y - 1 >= 0 && arr[x][y - 1] == '#' ) {
                        arr[x][y] = '^';
                        continue;
                    }
                    arr[x][y] = '.';
                    if (y - 1 < 0) break;
                    y--;
                    arr[x][y] = '<';
                }
            }

            if (hash) {
                arr[i][j] = '.';
            }
        }
    }

    cout << ans << '\n';

}