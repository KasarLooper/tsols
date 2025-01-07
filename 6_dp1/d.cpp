#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            int a = 0, b = 0;
            if (i - 1 >= 0 && j - 2 >= 0) a = dp[i - 1][j - 2];
            if (i - 2 >= 0 && j - 1 >= 0) b = dp[i - 2][j - 1];
            dp[i][j] = a + b;
        }
    cout << dp[n - 1][m - 1];
}