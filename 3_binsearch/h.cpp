#include <iostream>
#include <vector>

using namespace std;

bool check(int n, int k, vector<long long> a, long long m) {
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += a[i] / m;
    return cnt >= k;
}

int main() {
    int n, k;
    long long l = 0, r;
    cin >> n >> k;
    vector<long long> a(n);
    cin >> r;
    a[0] = r;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        r = min(r, a[i]);
    }
    r += 1;

    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (check(n, k, a, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}