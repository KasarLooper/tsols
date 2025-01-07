#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << k;
        return 0;
    }

    vector<long long> a1(k, 1), a2(k, 1);
    vector<long long> b1(k), b2(k);
    for (int i = 1; i < n; i++) {
        b1[0] = 0;
        b2[k - 1] = 0;
        for (int j = 1; j < k; j++) {
            b1[j] = b1[j - 1] + a2[j - 1];
            b1[j] %= mod;
        }

        for (int j = k - 2; j >= 0; j--) {
            b2[j] = b2[j + 1] + a1[j + 1];
            b2[j] %= mod;
        }

        for (int j = 0; j < k; j++) {
            a1[j] = b1[j];
            a2[j] = b2[j];
        }
    }

    long long sum = 0;
    for (int j = 0; j < k; j++) {
        sum += b1[j] + b2[j];
        sum %= mod;
    }

    cout << sum;
}