#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m;
    vector<int> cost(n * m);
    for (int i = 0; i < n * m; i++)
        cin >> cost[i];
    cin >> k;
    vector<int> min_cost(k);
    for (int i = 0; i < k; i++)
        cin >> min_cost[i];
    sort(cost.begin(), cost.end());
    sort(min_cost.begin(), min_cost.end());

    int i = 0, j = 0;
    int cnt = 0;
    while (i < n * m && j < k) {
        if (cost[i] >= min_cost[j]) {
            cnt += 1;
            j++;
        }
        i++;
    }
    cout << cnt;
}