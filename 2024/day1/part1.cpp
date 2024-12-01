
#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

FILE *inputFile;
int num;
int x = 0;
int ans = 0;
vector<int> list1;
vector<int> list2;

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

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    
    for (int i = 0; i < list1.size(); i++) {
        ans += abs(list1[i] - list2[i]);
    }

    cout << ans << '\n';

}