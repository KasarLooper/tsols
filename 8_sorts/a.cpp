#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& a, int n) {
    bool again = false;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i + 1] < a[i]) {
            swap(a[i], a[i + 1]);
            again = true;
        }
    }
    if (again) bubble_sort(a, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bubble_sort(a, n);
    for (int el : a) cout << el << ' ';
}