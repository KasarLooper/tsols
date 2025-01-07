#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr;
    unordered_map<long long, vector<int>> indexes;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
        indexes[x].push_back(i);
    }

    int res = 0;
    for (long long a : arr) {
        long long b = k - a;
        int size = indexes[b].size();
        if (a == b) {
            if (size >= 2) res += size - 1;
        }
        else if (size >= 1) res += size;
    }
    res /= 2;

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}