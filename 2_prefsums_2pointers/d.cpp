#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dif1(n + 1, vector<ll>(m + 1, 0));

    for (int _ = 0; _ < q; _++) {
        int lx, ly, rx, ry, d;
        cin >> ly >> lx >> ry >> rx >> d;

        dif1[ly - 1][lx - 1] += d;
        dif1[ly - 1][rx] -= d;
        dif1[ry][lx - 1] -= d;
        dif1[ry][rx] += d;
    }

    vector<vector<ll>> dif2(n, vector<ll>(m, 0));
    for (int j = 0; j < m; j++) {
        dif2[0][j] = dif1[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dif2[i][j] = dif1[i][j] + dif2[i - 1][j];
        }
    }

    vector<vector<ll>> res(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        res[i][0] = dif2[i][0];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            res[i][j] = dif2[i][j] + res[i][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

