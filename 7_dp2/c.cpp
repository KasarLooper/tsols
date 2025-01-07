#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e6;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> min_end(n + 1, inf);
    vector<int> idx(n + 1, -1);
    vector<int> prev(n, -1);
    min_end[0] = -inf;

    int len = 0;
    for (int j = 0; j < n; j++) {
        int i = lower_bound(min_end.begin(), min_end.begin() + len + 1, a[j]) - min_end.begin();
        min_end[i] = a[j];
        idx[i] = j;
        prev[j] = idx[i - 1];
        len = max(i, len);
    }
    cout << len << '\n';

    int i = idx[len];
    vector<int> res;
    while (i != -1) {
        res.push_back(a[i]);
        i = prev[i];
    }
    reverse(res.begin(), res.end());

    for (int el : res)
        cout << el << ' ';
}