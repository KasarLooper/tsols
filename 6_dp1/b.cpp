#include <iostream>
#include <vector>

using namespace std;

int min_cost(vector<int>& cost, int n) {
    vector<int> dp(n);
    // dp[-1] = 0;
    dp[0] = cost[0];
    for (int i = 1; i < n; i++) {
        int a = 0;
        if (i - 2 >= 0) a = dp[i - 2];
        int b = dp[i - 1];
        dp[i] = min(a, b) + cost[i];
    }
    return dp[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << min_cost(a, n);
}