# include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long** a = new long long* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new long long[m];
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    long long** pref = new long long*[n + 1];
    for (int i = 0; i <= n; i++) {
        pref[i] = new long long[m + 1];
        pref[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
        pref[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i - 1][j - 1];

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        long long ans = pref[rx][ry] + pref[lx - 1][ly - 1] - pref[lx - 1][ry] - pref[rx][ly - 1];
        cout << ans << ' ';
    }
}