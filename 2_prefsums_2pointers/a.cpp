#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    long long* a = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long* pref = new long long[n+1];
    pref[0] = 0;
    for (int i = 0; i < n; i++)
        pref[i+1] = pref[i] + a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        long long ans = pref[r] - pref[l - 1];
        cout << ans << ' ';
    }
}