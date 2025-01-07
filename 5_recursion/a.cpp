#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& a, int n) {
    if (a.size() >= n) {
        for (int byte : a) cout << byte;
        cout << '\n';
        return;
    }
    for (int add = 0; add <= 1; add++) {
        a.push_back(add);
        gen(a, n);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    gen(a, n);
    return 0;
}