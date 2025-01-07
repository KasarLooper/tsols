#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> a;
    string line;
    while (getline(cin, line)) {
        a.push_back(line);
    }

    sort(a.begin(), a.end(), [] (const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    });

    for (const string& el : a)
        cout << el;
}