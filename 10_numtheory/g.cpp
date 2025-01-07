#include <iostream>
#include <vector>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();

    int a, b;
    cin >> a >> b;

    vector<char> is_prime(b + 1, 1);
    for (int i = 2; i <= b; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= b; j += i)
                is_prime[j] = 0;
        }
    }

    for (int i = max(a, 2); i <= b; i++)
        if (is_prime[i])
            cout << i << ' ';

}