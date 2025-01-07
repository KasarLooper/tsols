#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int> a, int n, int last) {
    if (n <= 0) {
        for (int num : a) cout << num << ' ';
        cout << '\n';
        return;
    }
    for (int add = n; add >= last; add--) {
        a.push_back(add);
        gen(a, n - add, add);
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    gen(a, n, 1);
}