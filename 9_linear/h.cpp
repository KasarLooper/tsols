#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    int l = 1, r = 1;
    int mx = s;
    int mx_l = 1, mx_r = 1;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        if (s < 0) {
            s = 0;
            l = i;
            r = i - 1;
        }
        s += x;
        r++;

        if (s > mx) {
            mx = s;
            mx_l = l;
            mx_r = r;
        }
    }

    cout << mx_l << ' ' << mx_r << ' ' << mx << '\n';
}