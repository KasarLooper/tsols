
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int> m(n), c(n);
    for (int i = 0; i < n; i++) cin >> m[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++) {
            if (j >= m[i - 1]) dp[i][j] = max(dp[i - 1][j - m[i - 1]] + c[i - 1], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    int i = n, j = w;
    vector<int> res;
    while (i > 0 && j > 0) {
        if (j >= m[i - 1] && dp[i - 1][j - m[i - 1]] + c[i - 1] >= dp[i - 1][j]) {
            j -= m[i - 1];
            res.push_back(i);
        }
        i -= 1;
    }
    cout << res.size() << '\n';
    for (int el : res) cout << el << ' ';
}