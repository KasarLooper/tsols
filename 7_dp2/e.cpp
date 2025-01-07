#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int> m(n);
    for (int i = 0; i < n; i++) cin >> m[i];
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++) {
            if (j >= m[i - 1]) dp[i][j] = max(dp[i - 1][j - m[i - 1]] + m[i - 1], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][w];
}