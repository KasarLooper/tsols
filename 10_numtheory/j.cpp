#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> prime(n + 1, 1);
    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    for (int a = 2; a < n; a++) {
        if (prime[a]) {
            int b = n - a;
            if (b >= 2 && prime[b]) {
                cout << a << ' ' << b;
                return 0;
            }
        }
    }
}