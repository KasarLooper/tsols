#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    const int inf = 1e9;
    vector<int> dp(n + 1, inf);
    dp[1] = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] == inf) continue;
        if (i * 3 <= n) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        if (i * 2 <= n) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if (i + 1 <= n) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    cout << dp[n] << '\n';

    vector<int> arr;
    arr.push_back(n);
    while (arr.back() > 1) {
        int a = inf, b = inf, c = inf;
        if (arr.back() % 3 == 0) a = dp[arr.back() / 3];
        if (arr.back() % 2 == 0) b = dp[arr.back() / 2];
        if (arr.back() - 1 >= 1) c = dp[arr.back() - 1];
        if (a == inf && b == inf && c == inf) throw invalid_argument("Directed by Robert B. Weide");
        if (a <= b && a <= c)
            arr.push_back(arr.back() / 3);
        else if (b <= a && b <= c)
            arr.push_back(arr.back() / 2);
        else if (c <= a && c <= b)
            arr.push_back(arr.back() - 1);
    }
    for (int i = arr.size() - 1; i >= 0; i--) cout << arr[i] << ' ';
}