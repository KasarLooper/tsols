#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
vector<ll> fact;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll bin_pow(ll a, ll p) {
    if (p == 0)
        return 1;
    a %= mod;
    if (p % 2 == 1)
        return (bin_pow(a, p - 1) * a) % mod;
    ll b = bin_pow(a, p / 2) % mod;
    return (b * b) % mod;
}

void init_fact(ll n) {
    fact = vector<ll>(n + 1, 1);
    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}

ll mod_divide(ll a, ll b) {
    return (a % mod) * (bin_pow(b, mod - 2)) % mod;
}

ll comb(ll n, ll m) {
    return mod_divide(fact[n], (fact[m] * fact[n - m]) % mod);
}

int main() {
    fastIO();

    ll n, k;
    cin >> n >> k;

    init_fact(k);

    ll sum = 0;
    for (int t = 0; t <= k; t++) {
        if (n - 2 * t < 0 || k - t < n - 2 * t) continue;
        sum += comb(k, t) * comb(k - t, n - 2 * t) % mod;
        sum %= mod;
    }

    cout << sum;
}