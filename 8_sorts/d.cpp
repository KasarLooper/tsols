#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int p = 0;
    for (int el : a) p = max(p, el);
    int n = 0;
    for (int el : a) n = min(n, el);
    vector<int> cnt(p - n + 1, 0);
    for (int el : a) cnt[el - n] += 1;
    for (int i = 0; i <= p - n; i++)
        for (int j = 0; j < cnt[i]; j++)
            cout << i + n << ' ';
}