#include <iostream>

using namespace std;

int main() {
    long long n;
    int x, y;
    cin >> n >> x >> y;
    int first = min(x, y);
    if (n == 1) {
        cout << first;
        return 0;
    }
    n -= 1;
    long long l = -1;
    long long r = max(x, y) * n;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (m / x + m / y >= n)
            r = m;
        else
            l = m;
    }
    cout << r + first;
}