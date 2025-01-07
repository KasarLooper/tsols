#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    int l = 0, r = k - 1;
    ll mx = pref[k];
    for (int i = 1; i <= n - k; i++) {
        ll cur = pref[i + k] - pref[i];
        if (cur > mx) {
            mx = cur;
            l = i;
            r = i + k - 1;
        }
    }

    mx = 0;
    for (int i = 1; i <= n - k; i++) {
        int j = i + k - 1;
        if ((i >= l && i <= r) || (j >= l && j <= r))
            continue;
        ll cur = pref[j + 1] - pref[i];
        mx = max(mx, cur);
    }

    cout << mx;
}
