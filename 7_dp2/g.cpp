#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];

    int sum = 0;
    for (int el : m)
        sum += el;

    if (sum % 2 == 1) {
        cout << "NO";
        return 0;
    }

    int half = sum / 2;
    vector<bool> dp(half + 1, false);
    dp[0] = true;

    for (int w : m) {
        for (int j = half; j >= w; j--) {
            dp[j] = dp[j] || dp[j - w];
        }
    }

    if (dp[half])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}