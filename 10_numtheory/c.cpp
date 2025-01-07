#include <iostream>
#include <map>
#include <valarray>

using namespace std;

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> res;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0 && prime(p)) {
            res[p]++;
            n /= p;
            p--;
        }
    }
    res[n]++;

    long long ans = 1;
    for (auto el : res) {
        int p = el.second;
        ans *= p + 1;
    }

    if (n != 1)
        cout << ans;
    else
        cout << 1;
}
