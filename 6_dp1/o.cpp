#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, n;
    cin >> k >> n;

    vector<ll> dp(n + 1);
    dp[0] = 1;

    ll sum = dp[0];
    for (ll i = 1; i <= n; ++i) {
	dp[i] = sum;
	if (i >= k)
		sum = (sum - dp[i - k] + MOD) % MOD;
	sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n];
}
