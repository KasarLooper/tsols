#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print_matr(vector<vector<int>>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
}

int main() {
    fastIO();

    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<ll> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prev(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                for (int k = 1; k < j; k++) {
                    if (b[k - 1] < b[j - 1]) {
                        if (dp[i - 1][k] + 1 > dp[i][j]) {
                            dp[i][j] = dp[i - 1][k] + 1;
                            prev[i][j] = k;
                        }
                    }
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                prev[i][j] = j;
            }
        }
    }
    cout << dp[n][m] << '\n';

    vector<ll> res;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1])
            res.push_back(a[i - 1]);

        i -= 1;
        j = prev[i + 1][j];
    }
    reverse(res.begin(), res.end());

    for (auto el : res)
        cout << el << ' ';
}