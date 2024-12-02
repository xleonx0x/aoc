
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

FILE *inputFile;
int num;
int x = 0;
int ans = 0;
vector<int> list1;
vector<int> list2;
std::unordered_map<int, int> freq;

int main(void) {
    inputFile = fopen("input.txt", "r");
    
    // read input
    while (fscanf(inputFile, "%d", &num) == 1) {
        // alternate between pushing to lists
        if (x % 2 == 0) {
            list1.push_back(num);
        } else {
            list2.push_back(num);
        }
        x++;
    }

    fclose(inputFile);

    // get frequency of all list2 numbers
    for (int num : list2) {
        if (freq.find(num) != freq.end()) {
            freq[num] += 1;
        } else {
            freq[num] = 1;
        }
    }

    // iterate over list1 and multiply it by freq
    for (int num : list1) {
        ans += num * freq[num];
    }

    cout << ans << '\n';
}