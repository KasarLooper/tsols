#include <iostream>

using namespace std;
typedef long long ll;

bool check(ll n, ll a, ll b, ll w, ll h, ll guess) {
	ll a1 = a + 2 * guess;
	ll b1 = b + 2 * guess;
	ll cnt1 = (w / a1) * (h / b1);
	ll cnt2 = (w / b1) * (h / a1);
	return max(cnt1, cnt2) >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, a, b, w, h;
	cin >> n >> a >> b >> w >> h;

	ll l = 0, r = max(w, h);
	ll m;
	while (l + 1 < r) {
		m = (l + r) / 2;
		if (check(n, a, b, w, h, m))
			l = m;
		else
			r = m;
	}

	cout << l << '\n';
}
