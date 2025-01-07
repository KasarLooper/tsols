#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a0, k, b, m;
    cin >> n >> a0 >> k >> b >> m;
    vector<int> a(n);
    a[0] = a0;
    for (int i = 1; i < n; i++)
        a[i] = (k * a[i - 1] + b) % m;

    vector<int> min_end(n + 1, inf);
    min_end[0] = -inf;

    for (int i = 0; i < n; ++i) {
        int j = lower_bound(min_end.begin(), min_end.end(), a[i]) - min_end.begin();
        min_end[j] = a[i];
    }

    int len = lower_bound(min_end.begin(), min_end.end(), inf) - min_end.begin() - 1;
    cout << len;
}