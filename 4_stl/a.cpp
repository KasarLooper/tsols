#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, string> m;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        m[s1] = s2;
        m[s2] = s1;
    }
    string s;
    cin >> s;
    cout << m[s];
}