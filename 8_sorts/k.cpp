#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, n;
    cin >> b >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b) {
            cnt++;
            b = a[i] + 3;
        }
    }

    cout << cnt;
}