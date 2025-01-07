#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y, i + 1});
        if (x != y)
            arr.push_back({y, x, i + 1});
    }

    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    });

    long long m = arr.size();
    vector<int> a(m);
    vector<int> idx(m);
    for (int i = 0; i < m; i++) {
        a[i] = arr[i][1];
        idx[i] = arr[i][2];
    }

    vector<int> min_end(m + 1, inf);
    vector<long long> min_idx(m + 1, -1);
    vector<long long> prev(m, -1);
    min_end[0] = -inf;
    for (long long i = 0; i < m; i++) {
        long long j = upper_bound(min_end.begin(), min_end.end(), a[i]) - min_end.begin();
        min_end[j] = a[i];
        min_idx[j] = i;
        prev[i] = min_idx[j - 1];
    }

    int len = lower_bound(min_end.begin(), min_end.end(), inf) - min_end.begin() - 1;
    cout << len << '\n';

    long long i = min_idx[len];
    vector<int> res;
    while (i != -1) {
        res.push_back(idx[i]);
        i = prev[i];
    }
    reverse(res.begin(), res.end());

    for (int el : res)
        cout << el << ' ';
}