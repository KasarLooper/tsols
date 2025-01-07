#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& a, int n, int k) {
    if (a.size() >= n) {
        for (int digit : a) cout << digit;
        cout << '\n';
        return;
    }
    for (int add = 0; add < k; add++) {
        a.push_back(add);
        gen(a, n, k);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    vector<int> a;
    cin >> n >> k;
    gen(a, n, k);
}