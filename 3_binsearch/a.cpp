#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool contains(const vector<long long>& a, long long x, int n) {
    int l = -1, r = n - 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] >= x)
            r = m;
        else
            l = m;
    }
    return a[r] == x;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        long long x;
        cin >> x;
        bool yes = contains(a, x, n);
        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}