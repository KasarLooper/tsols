#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int> a, int n, int m) {
    if (n == 1) {
        for (auto it = a.begin(); it != a.end(); it++) {
            if (it != a.begin()) cout << '*';
            cout << *it;
        }
        cout << '\n';
        return;
    }
    for (int i = m; i <= n; i++) {
        if (n % i != 0) continue;
        int n1 = n / i;
        if (n1 < min(n, i) && n1 != 1) continue;
        a.push_back(i);
        gen(a, n1, m);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    gen(a, n, m);
}