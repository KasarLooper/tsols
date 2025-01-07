#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& a, int n, int k) {
    if (n - a.size() < k) return;
    if (a.size() >= n) {
        for (int digit: a) cout << digit;
        cout << '\n';
        return;
    }
    if (n - a.size() != k) {
        a.push_back(0);
        gen(a, n, k);
        a.pop_back();
    }
    a.push_back(1);
    gen(a, n, k - 1);
    a.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    vector<int> a;
    cin >> n >> k;
    gen(a, n, k);
}