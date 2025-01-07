#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int mn = i;
        for (int j = i; j < n; j++)
            if (a[j] < a[mn]) mn = j;
        swap(a[mn], a[i]);
    }
    for (int el : a) cout << el << ' ';
}