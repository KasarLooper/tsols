#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> dp(n);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
        dp[i] = a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
                prev[i] = j;
            }
    }

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (dp[j] > dp[i])
            i = j;
    }

    vector<int> res;
    while (i != -1) {
        res.push_back(a[i]);
        i = prev[i];
    }
    reverse(res.begin(), res.end());

    for (auto el : res)
        cout << el << ' ';
}