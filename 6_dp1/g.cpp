#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(10, 1));
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][9] = dp[i - 1][9] + dp[i - 1][8];
        for (int j = 1; j <= 8; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
    }
    int ans = 0;
    for (int cur : dp[n - 1]) ans += cur;
    cout << ans;
}