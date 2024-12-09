#include <bits/stdc++.h>

#define PRINT(x) cout << x << '\n'
#define ll long long
#define ARR2(x) for (auto i: x) {for (auto j: i) {{cout << j;}}cout << '\n';}
#define ARR1(x) for (auto i: x) {cout << i;} cout << '\n';

using namespace std;
using namespace std::chrono;


FILE *inputFile;
vector<ll> arr;
vector<ll> disk;

ll ans = 0;

int main(void) {
    auto start = high_resolution_clock::now();
    // // Optimize input and output
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
    for (ll i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            space = false;
        } else {
            space = true;
        }
        ll j = 0;
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

    ll Ids = (arr.size() - 1) / 2;

    while (Ids >= 0) {
        ll j = disk.size() - 1;
        bool in_file = false;
        for (int i = 0; i < disk.size(); i++) {
            if (disk[i] == Ids) {
                in_file = true;
            }
        }
        if (in_file == false) {
            Ids--;
            continue;
        }
        
        while (disk[j] != Ids) {
            j--;
        }
        
        ll file_range = 0;
        while (j >= 0 && disk[j] == Ids) {
            j--;
            file_range++;
        }

        ll i = 0;
        while (i < j) {
            while (disk[i] != -1) {
                i++;
            }
            ll space_range = 0;
            while (disk[i] == -1) {
                i++;
                space_range++;
            }
            if (i > j + 1) break;
            // ^^^ kms spent 4hrs just to add a + 1 
            if (file_range <= space_range) {
                for (ll k = i - space_range, q = j + 1, count = 0; count < file_range; k++, q++, count++) {
                    swap(disk[k], disk[q]);
                }
                break;
            }
        }
        Ids--;
    }
   

    ll pos = 0;
    for (auto i: disk) {
        if (i == -1) {
            pos++;
            continue;
        }
        ans += i * pos; 
        pos++;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    // PRINT(duration.count());
    PRINT(ans);
}
