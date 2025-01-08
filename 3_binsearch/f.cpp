#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, k;
    cin >> a >> b >> k;

    ll res = 0;
    for (ll y = 1; ; y++) {
        ll cube = y * y * y;
        if (cube > b) break;

        if (cube >= a) {
            ll left = max(a, cube - k);
            ll right = min(b, cube + k);
            if (left > right) continue;

            ll i = ceil(sqrt(left));
            ll j = floor(sqrt(right));

            res += j - i + 1;
        }
    }

    cout << res << '\n';
    return 0;
}
