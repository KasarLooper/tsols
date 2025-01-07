#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<long>> cost(n, vector<long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> cost[i][j];

    vector<vector<long>> dp(n, vector<long>(m));
    dp[0][0] = cost[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            long left = 0, up = 0;
            int i0 = i - 1;
            int j0 = j - 1;
            if (i0 >= 0) up = dp[i0][j];
            if (j0 >= 0) left = dp[i][j0];
            dp[i][j] = cost[i][j] + max(up, left);
        }

    long res = dp[n - 1][m - 1];
    cout << res << '\n';

    int i = n - 1, j = m - 1;
    vector<char> path;
    while (i > 0 || j > 0) {
        if (i == 0) {
            path.push_back('R');
            j -= 1;
        }
        else if (j == 0) {
            path.push_back('D');
            i -= 1;
        }
        else {
            long up = dp[i - 1][j];
            long left = dp[i][j - 1];
            if (up > left) {
                path.push_back('D');
                i -= 1;
            }
            else {
                path.push_back('R');
                j -= 1;
            }
        }
    }

    for (int k = path.size() - 1; k >= 0; k--)
        cout << path[k] << ' ';
}