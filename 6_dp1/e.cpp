#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(n, vector<long long>(m));
    dp[0][0] = 1;
    for (int k = 1; k < m; k++) {
        int i = 0;
        int j = k;
        while (i < n && j >= 0) {
            long long a = 0, b = 0, c = 0, d = 0;
            if (i + 1 < n && j - 2 >= 0) a = dp[i + 1][j - 2];
            if (i - 1 >= 0 && j - 2 >= 0) b = dp[i - 1][j - 2];
            if (i - 2 >= 0 && j - 1 >= 0) c = dp[i - 2][j - 1];
            if (i - 2 >= 0 && j + 1 < m) d = dp[i - 2][j + 1];
            dp[i][j] = a + b + c + d;

            i += 1;
            j -= 1;
        }
    }
    for (int k = 1; k < n; k++) {
        int i = k;
        int j = m - 1;
        while (i < n && j >= 0) {
            long long a = 0, b = 0, c = 0, d = 0;
            if (i + 1 < n && j - 2 >= 0) a = dp[i + 1][j - 2];
            if (i - 1 >= 0 && j - 2 >= 0) b = dp[i - 1][j - 2];
            if (i - 2 >= 0 && j - 1 >= 0) c = dp[i - 2][j - 1];
            if (i - 2 >= 0 && j + 1 < m) d = dp[i - 2][j + 1];
            dp[i][j] = a + b + c + d;

            i += 1;
            j -= 1;
        }
    }
    cout << dp[n - 1][m - 1];
}