#include <iostream>

using namespace std;

int main() {
    int n;
    long long r;
    cin >> n >> r;
    long long* a = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0, j = 0;
    long long ans = 0;
    while (j < n) {
        if (a[j] - a[i] <= r)
            j += 1;
        else {
            ans += n - j;
            i += 1;
        }
    }
    cout << ans;
}