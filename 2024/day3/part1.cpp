
#include <bits/stdc++.h>
#include <regex>

using namespace std;

FILE *inputFile;
string line;
smatch last_do_match;

int ans = 0;
int num1;
int num2;
string avaliable;

int main(void) {
    ifstream inputFile("input.txt");

    stringstream buffer;
    buffer << inputFile.rdbuf(); 
    string content = buffer.str(); 

    regex pattern("mul\\(\\d{1,3},\\d{1,3}\\)");
    regex nums("\\d{1,3}");

    auto iterate = sregex_iterator(content.begin(), content.end(), pattern);
    auto end = sregex_iterator();


    for (auto it = iterate; it != end; ++it) {
        smatch match = *it;

        auto iterate = sregex_iterator(match.str().begin(), match.str().end(), nums);
        smatch number = *iterate;
        smatch number2 = *(++iterate);

        stringstream(number.str()) >> num1;
        stringstream(number2.str()) >> num2;
        ans += num1 * num2;
        
    }

    cout << ans << '\n';
}