
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
std::unordered_map<int, int> dict;

int main(void) {
    inputFile = fopen("input.txt", "r");
    
    while (fscanf(inputFile, "%d", &num) == 1) {
        if (x % 2 == 0) {
            list1.push_back(num);
        } else {
            list2.push_back(num);
        }
        x++;
    }

    fclose(inputFile);

    for (int num : list2) {
        if (dict.find(num) != dict.end()) {
            dict[num] += 1;
        } else {
            dict[num] = 1;
        }
    }

    for (int num : list1) {
        ans += num * dict[num];
    }

    cout << ans << '\n';
}