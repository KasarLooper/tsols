#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& a, vector<bool>& used, int n) {
    if (a.size() >= n) {
        for (int digit : a) cout << digit;
        cout << '\n';
        return;
    }
    for (int add = 1; add <= n; add++) {
        if (used[add]) continue;
        used[add] = true;
        a.push_back(add);
        gen(a, used, n);
        used[add] = false;
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    vector<bool> b(n + 1, false);
    gen(a, b, n);
}