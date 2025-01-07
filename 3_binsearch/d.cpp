
#include <iostream>

using namespace std;

int main() {
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    long long l = 0, r = min(w, h);
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if ((w / (a + m * 2)) * (h / (b + m * 2)) >= n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if (l == 0) cout << 0 << endl;
    else cout << l + (r - l + 1) / 2 << endl;
}