#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<long>> dp(n, vector<long>(3, 1));
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i][0] + dp[i - 1][0];
        dp[i][2] = dp[i][1];
    }
    long ans = 0;
    for (long cur : dp[n - 1]) ans += cur;
    cout << ans;
}