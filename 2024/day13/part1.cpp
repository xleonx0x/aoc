#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';
#define int long long

using namespace std;

FILE *inputFile;
vector<vector<char>> arr;

struct Button {
    int x;
    int y;
};

struct Prize {
    int x;
    int y;
};

vector<Button> buttonsA;
vector<Button> buttonsB;
vector<Prize> prizes;

ll ans;

int main(void) {

    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    ifstream inputFile("input.txt");
    string line;


    while (getline(inputFile, line)) {
        if (line.find("Button A:") != string::npos) {
            Button buttonA;
            sscanf(line.c_str(), "Button A: X+%d, Y+%d", &buttonA.x, &buttonA.y);
            buttonsA.push_back(buttonA);
        } else if (line.find("Button B:") != string::npos) {
            Button buttonB;
            sscanf(line.c_str(), "Button B: X+%d, Y+%d", &buttonB.x, &buttonB.y);
            buttonsB.push_back(buttonB);
        } else if (line.find("Prize:") != string::npos) {
            Prize prize;
            sscanf(line.c_str(), "Prize: X=%d, Y=%d", &prize.x, &prize.y);
            prizes.push_back(prize);
        }
    }


    for (int i = 0; i < buttonsA.size(); i++) {
        ll dp[100000][100000];
        dp[buttonsA[i].x][buttonsA[i].y] = 3;
        dp[buttonsB[i].x][buttonsB[i].y] = 1;

        for (int j = 0; j < prizes[i].x; j++) {
            for (int k = 0; j < prizes[i].y; j++) {
                
            }
        }
    }


    PRINT(ans);
}