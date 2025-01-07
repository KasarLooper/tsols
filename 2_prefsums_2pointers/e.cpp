#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k;
    vector<vector<vector<long long>>> a(n, vector<vector<long long>>(m, vector<long long>(k, 0)));
    for (int z = 0; z < n; z++)
        for (int y = 0; y < m; y++)
            for (int x = 0; x < k; x++)
                cin >> a[z][y][x];

    vector<vector<vector<long long>>> pref(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0)));
    for (int z = 1; z <= n; z++)
        for (int y = 1; y <= m; y++)
            for (int x = 1; x <= k; x++)
                pref[z][y][x] = a[z - 1][y - 1][x - 1]

                                - pref[z - 1][y][x]
                                - pref[z][y - 1][x]
                                - pref[z][y][x - 1]

                                + pref[z - 1][y - 1][x]
                                + pref[z][y - 1][x - 1]
                                + pref[z - 1][y][x - 1]

                                - pref[z - 1][y - 1][x - 1];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int lx, ly, lz, rx, ry, rz;
        cin >> lx >> ly >> lz >> rx >> ry >> rz;

        long long ans = pref[rz][ry][rx]

                        + pref[lz - 1][ry][rx]
                        + pref[rz][ly - 1][rx]
                        + pref[rz][ry][lx - 1]

                        - pref[lz - 1][ly - 1][rx]
                        - pref[lz - 1][ry][lx - 1]
                        - pref[rz][ly - 1][lx - 1]

                        + pref[lz - 1][ly - 1][lx - 1];

        cout << ans << ' ';
    }
}