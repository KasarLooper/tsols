#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        int l = -1, r = n;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] >= x)
                r = m;
            else
                l = m;
        }
        if (l < 0) cout << a[0] << endl;
        else if (r >= n) cout << a[n - 1] << endl;
        else if (abs(a[l] - x) <= abs(a[r] - x)) cout << a[l] << endl;
        else cout << a[r] << endl;
    }
}