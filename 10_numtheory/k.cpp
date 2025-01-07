#include <iostream>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve(int n, int m) {
    return gcd(n - 1, m - 1) + 1;
}

int main() {
    fastIO();

    int n, m;
    cin >> n >> m;

    cout << solve(n, m);
}