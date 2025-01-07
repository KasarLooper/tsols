#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    cin >> s;

    vector<int> dp(s + 1, inf);
    vector<int> prev(s + 1, -1);
    vector<int> coins(s + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j < n && i >= a[j]; j++) {
            if (dp[i - a[j]] + 1 < dp[i]) {
                dp[i] = dp[i - a[j]] + 1;
                coins[i] = a[j];
                prev[i] = i - a[j];
            }
        }
    }

    if (dp[s] == inf) cout << -1;
    else {
        vector<int> res;
        int i = s;
        while (i > 0) {
            res.push_back(coins[i]);
            i = prev[i];
        }
        for (int el : res)
            cout << el << ' ';
    }
}