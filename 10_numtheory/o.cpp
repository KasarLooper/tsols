#include <iostream>

typedef long long ll;

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll bin_pow(ll a, ll p, ll mod) {
    if (p == 0)
        return 1;
    a %= mod;
    if (p % 2 == 1)
        return (bin_pow(a, p - 1, mod) * a) % mod;
    ll b = bin_pow(a, p / 2, mod) % mod;
    return (b * b) % mod;
}

int main() {
    fastIO();

    ll a, p;
    cin >> a >> p;

    ll res = bin_pow(a, p - 2, p);
    cout << res;
}