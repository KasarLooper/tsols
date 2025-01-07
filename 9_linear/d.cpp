#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int x;
    vector<vector<bool>> white(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x == 0)
                white[i][j] = true;
        }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        if (white[0][j])
            dp[0][j] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (white[i][j])
                dp[i][j] = 1 + dp[i - 1][j];
            else
                dp[i][j] = 0;
        }

    ll mx = 0;
    vector<int> l(m), r(m);
    for (int i = 0; i < n; i++) {
        deque<int> st1, st2;
        for (int j = 0; j < m; j++) {
            while (!st1.empty() && dp[i][st1.back()] >= dp[i][j])
                st1.pop_back();
            if (st1.empty())
                l[j] = -1;
            else
                l[j] = st1.back();
            st1.push_back(j);
        }

        for (int j = m - 1; j >= 0; j--) {
            while (!st2.empty() && dp[i][st2.back()] >= dp[i][j])
                st2.pop_back();
            if (st2.empty())
                r[j] = m;
            else
                r[j] = st2.back();
            st2.push_back(j);
        }

        for (int j = 0; j < m; j++) {
            ll width = r[j] - l[j] - 1;
            if (width > 0) {
                ll cur = width * dp[i][j];
                if (cur > mx)
                    mx = cur;
            }
        }
    }

    cout << mx;
}