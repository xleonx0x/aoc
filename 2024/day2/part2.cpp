
#include <bits/stdc++.h>

using namespace std;

FILE *inputFile;

vector<vector<int>> reports;
int num;
int safe = 0;
bool increasing;
bool decreasing;
bool isSafe;
int erasedElement;

int main(void) {
    ifstream inputFile("input.txt");
    string line;
    int length;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> row;
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        num = row.size();
        reports.push_back(row);
    }

    for (int i = 0; i < reports.size(); ++i) {
        increasing = false;
        decreasing = false;
        isSafe = true;
         for (int j = 0; j < reports[i].size(); ++j) {
            if (j != 0 && reports[i][j - 1] > reports[i][j]) {
                decreasing = true;
            } else if (j != 0 && reports[i][j - 1] < reports[i][j]) {
                increasing = true;
            }
            if (j != 0 && abs(reports[i][j - 1] - reports[i][j]) > 3 || abs(reports[i][j - 1] - reports[i][j]) < 1 || (increasing && decreasing)) {
                isSafe = false;
                break;
            }
        }


        if (isSafe) {
            safe++;
            continue;
        }

        for (int k = 0; k < reports[i].size(); ++k) {
            increasing = false;
            decreasing = false;
            isSafe = true;

            erasedElement = reports[i][k];
            reports[i].erase(reports[i].begin() + k);
            
            for (int j = 0; j < reports[i].size(); ++j) {
                if (j != 0 && reports[i][j - 1] > reports[i][j]) {
                    decreasing = true;
                } else if (j != 0 && reports[i][j - 1] < reports[i][j]) {
                    increasing = true;
                }
                if (j != 0 && abs(reports[i][j - 1] - reports[i][j]) > 3 || abs(reports[i][j - 1] - reports[i][j]) < 1 || (increasing && decreasing)) {
                    isSafe = false;
                    break;
                }
            }

            if (k == reports[i].size() && !isSafe) {
                safe--;
            };

            reports[i].insert(reports[i].begin() + k, erasedElement);

            if (isSafe) {
                break;
            }
        }
        safe++;
    }

    cout << safe << '\n';
}