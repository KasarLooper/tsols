#include <iostream>

typedef long long ll;

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    fastIO();

    ll n;
    cin >> n;

    ll sum = 0;
    ll x1, y1, x2, y2;

    cin >> x1 >> y1;

    ll x0, y0;
    x0 = x1;
    y0 = y1;

    for (int i = 1; i < n; i++) {
        cin >> x2 >> y2;
        ll dx = abs(x1 - x2);
        ll dy = abs(y1 - y2);
        sum += gcd(dx, dy);
        x1 = x2;
        y1 = y2;
    }

    ll dx = abs(x0 - x2);
    ll dy = abs(y0 - y2);
    sum += gcd(dx, dy);

    cout << sum;
}