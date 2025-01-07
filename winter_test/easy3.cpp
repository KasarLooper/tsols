#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

__int128 mg(int a, string s) {
    __int128 res = a * 1000;
    if (s.size() == 1) {
        if (s[0] == 'p')
            res *= 16380;
        if (s[0] == 't')
            res *= 1000000;
    } else {
        if (s[1] == 'p')
            res *= 16380;
        if (s[1] == 't')
            res *= 1000000;

        if (s[0] == 'm')
            res /= 1000;
        if (s[0] == 'k')
            res *= 1000;
        if (s[0] == 'M')
            res *= 1000000;
        if (s[0] == 'G')
            res *= 1000000000;
    }
    return res;
}

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    __int128 a1 = mg(a.first, a.second);
    __int128 b1 = mg(b.first, b.second);
    if (a1 != b1)
        return a1 < b1;
    else
        return a.second < b.second;
}

int main() {
    fastIO();

    int n;
    cin >> n;

    vector<pair<int, string>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        string s;
        cin >> m >> s;
        a[i] = make_pair(m, s);
    }

    sort(a.begin(), a.end(), compare);

    for (auto el : a) {
        cout << el.first << ' ' << el.second << '\n';
    }
}

