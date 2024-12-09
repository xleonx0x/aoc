#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';
#define ll long long

using namespace std;
using namespace std::chrono;


FILE *inputFile;
vector<ll> arr;
vector<ll> disk;

ll ans = 0;

int main(void) {
    auto start = high_resolution_clock::now();
    // Optimize input and output
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    
    ifstream inputFile("input.txt");
    string line;

    getline(inputFile, line);
    for (char num: line) {
        arr.push_back((ll)(num - '0'));
    }
    ll id = 0;
    bool space = false;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            space = false;
        } else {
            space = true;
        }
        int j = 0;
        while (j < arr[i]) {
            if (space == true) {
                disk.push_back(-1);
            } else {
                disk.push_back(id);
            }
            j++;
        }
        if (space == false) {
            id++;
        }
    }

    int i = 0;
    int j = disk.size() - 1;

    while (i < j) {
        while (disk[i] != -1) {
            i++;
        }
        while (disk[j] == -1) {
            j--;
        }
        swap(disk[i], disk[j]);
        i++;
        j--;
    }
    i = 0;
    j = disk.size() - 1;
    while (i < j) {
        while (disk[i] != -1) {
            i++;
        }
        while (disk[j] == -1) {
            j--;
        }
        swap(disk[i], disk[j]);
        i++;
        j--;
    }
    ARR1(disk);
    int idCount = 0;
    for (auto i: disk) {
        if (i == -1) break;
        ans += i * idCount; 
        idCount++;
    }


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // PRINT(duration.count());
    PRINT(ans);
}
