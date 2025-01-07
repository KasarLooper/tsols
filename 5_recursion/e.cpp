#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& a, int n, int k) {
    if (n - a.size() > k) return;
    if (a.size() >= n) {
        for (int digit : a) cout << digit << ' ';
        cout << '\n';
        return;
    }
    for (int add = 1; add <= k; add++) {
        a.push_back(add);
        gen(a, n, add - 1);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    vector<int> a;
    cin >> k >> n;
    gen(a, n, k);
}