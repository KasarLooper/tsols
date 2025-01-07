#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    vector<int> dp(n);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + a[i];
        if (i - 2 >= 0)
            dp[i] = min(dp[i], dp[i - 2] + b[i - 1]);
        if (i - 3 >= 0)
            dp[i] = min(dp[i], dp[i - 3] + c[i - 2]);
    }
    cout << dp[n - 1] << '\n';
}