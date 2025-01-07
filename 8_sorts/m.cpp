#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> width(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        int mn_x = inf;
        int mx_x = -inf;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            mn_x = min(mn_x, x);
            mx_x = max(mx_x, x);
        }
        width[i] = {mx_x - mn_x, i};
    }
    sort(width.rbegin(), width.rend());
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[width[i].second] = i;
    for (int el : res)
        cout << el << ' ';
}