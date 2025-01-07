#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<long long> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    long long p = a[0];
    for (auto el : a) p = max(p, el);
    long long n = a[0];
    for (auto el : a) n = min(n, el);
    vector<long long> cnt(p - n + 1, 0);
    for (auto el : a) cnt[el - n] += 1;
    for (long long i = 0; i <= p - n; i++)
        for (long long j = 0; j < cnt[i]; j++)
            cout << i + n << ' ';
}