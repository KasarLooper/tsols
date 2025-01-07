#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = min(a, min(b, c)); i < n; i++) {
        int a_cond = i - a >= 0 && dp[i - a];
        int b_cond = i - b >= 0 && dp[i - b];
        int c_cond = i - c >= 0 && dp[i - c];
        dp[i] = dp[i] || a_cond || b_cond || c_cond;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (dp[i]) cnt += 1;
    cout << cnt;
}