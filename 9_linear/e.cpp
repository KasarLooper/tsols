#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int ups = 0;
    for (int i = 1; i < k; i++) {
        if (h[i] > h[i - 1])
            ups++;
    }

    int mn = ups;
    for (int i = k; i < n; i++) {
        if (h[i] > h[i - 1])
            ups++;
        if (h[i - k + 1] > h[i - k])
            ups--;
        mn = min(mn, ups);
    }

    cout << mn;
}