#include <iostream>
#include <valarray>

using namespace std;

bool comp(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (comp(n))
        cout << "composite";
    else cout << "prime";
}