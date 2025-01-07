# include <iostream>

using namespace std;

int main() {
    long long ans = 0, s = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        if (s < x) s = x;
        if (s > ans) ans = s;
    }
    cout << ans;
}