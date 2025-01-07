#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    set<long long> res;
    cin >> n;
    unordered_set<long long> s1;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s1.insert(x);
    }

    cin >> m;
    unordered_set<long long> s2;
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        s2.insert(x);

        if (s1.find(x) == s1.end())
            res.insert(x);
    }

    for (auto el : s1) {
        if (s2.find(el) == s2.end())
            res.insert(el);
    }

    cout << res.size() << '\n';
    for (long long el : res)
        cout << el << ' ';
}