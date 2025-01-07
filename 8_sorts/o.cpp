#include <iostream>
#include <vector>

using namespace std;

const long long mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    a[0] = -abs(a[0]);
    for (int i = 1; i < n; i++) {
        if (-abs(a[i]) >= a[i - 1]) a[i] = -abs(a[i]);
        else if (abs(a[i]) >= a[i - 1]) a[i] = abs(a[i]);
        else {
            cout << 0;
            return 0;
        }
    }

    /*
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            throw exception();
    }
    */

    int neg = -1;
    for (int i = n - 1; i >= 0 && neg == -1; i--)
        if (a[i] < 0)
            neg = i;

    long long cnt = 1;
    for (int i = neg; i >= 0; i--) {
        if (i == n - 1 || -a[i] <= abs(a[i + 1])) cnt++;
        else break;
    }
    cnt %= mod;

    int zeros = 0;
    for (int el : a)
        if (el == 0)
            zeros++;

    long long cnt0 = 0;
    if (zeros != 0) {
        cnt0 = 2;
        for (int i = 1; i < zeros; i++) {
            cnt0 *= 2;
            cnt0 %= mod;
        }
        cnt0 -= 1;
    }

    long long res = cnt + cnt0;
    res %= mod;
    cout << res;
}