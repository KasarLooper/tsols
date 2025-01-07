#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    long long* diff = new long long[n];
    for (int i = 0; i < n; i++)
        diff[i] = 0;

    for (int i = 0; i < q; i++) {
        int l, r;
        long long d;
        cin >> l >> r >> d;
        diff[l - 1] += d;
        if (r < n) diff[r] -= d;
    }

    long long el = 0;
    for (int i = 0; i < n; i++) {
        el += diff[i];
        cout << el << ' ';
    }
}