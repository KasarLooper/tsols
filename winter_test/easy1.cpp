#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
	int n, k;
	cin >> n >> k;

	int res = n / gcd(n, k) * k;

	cout << res;
}
