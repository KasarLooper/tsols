#include <iostream>
#include <map>

using namespace std;

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> res;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0 && prime(p)) {
            res[p]++;
            n /= p;
            p--;
        }
    }
    res[n]++;

    bool first = true;
    for (auto el : res) {
        if (!first)
            cout << '*';
        first = false;
        int a = el.first;
        int p = el.second;
        cout << a;
        if (p != 1)
            cout << '^' << p;
    }
}