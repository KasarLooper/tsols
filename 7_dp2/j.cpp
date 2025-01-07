#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        if (s[i] != s[j])
            dp[i][j] = 1;
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = dp[i + 1][j - 1] + 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (dp[i][j] <= k)
                cnt++;

    cout << cnt;
}