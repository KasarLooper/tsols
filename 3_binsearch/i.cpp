#include <iostream>
#include <vector>

using namespace std;

bool fit(int n, int k, vector<long long> a, long long d) {
    int cnt = 1;
    long long last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= d) {
            last = a[i];
            cnt += 1;
        }
    }
    return cnt >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long l = 1, r = a[n - 1] - a[0] + 1;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (fit(n, k, a, m))
            l = m;
        else
            r = m;
    }
    cout << l;
}