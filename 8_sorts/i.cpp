#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26, 0);
    for (char& c: s) {
        int i = c - 'A';
        cnt[i] += 1;
    }

    int mid = -1;
    int m;
    for (int i = 0; i < 26; i++) {
        if (mid == -1 && cnt[i] % 2 == 1)
            mid = i;
        m = cnt[i] / 2;
        for (int j = 0; j < m; j++)
            cout << char('A' + i);
    }

    if (mid != -1)
        cout << char('A' + mid);

    for (int i = 26 - 1; i >= 0; i--) {
        m = cnt[i] / 2;
        for (int j = 0; j < m; j++)
            cout << char('A' + i);
    }

    cout << '\n';
}