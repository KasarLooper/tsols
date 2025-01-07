#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n, 1);
    if (n >= 2) dp[1] = 4;
    if (n >= 3) dp[2] = 7;
    for (int i = 3; i < n; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    cout << dp[n - 1];
}