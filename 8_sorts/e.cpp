#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int l, int m, int r, vector<int>& buf) {
    int i = 0, j = 0;
    while (l + i < m && m + j < r) {
        if (a[l + i] <= a[m + j]) {
            buf[i + j] = a[l + i];
            i += 1;
        }
        else {
            buf[i + j] = a[m + j];
            j += 1;
        }
    }
    while (l + i < m) {
        buf[i + j] = a[l + i];
        i += 1;
    }
    while (m + j < r) {
        buf[i + j] = a[m + j];
        j += 1;
    }
    for (int k = 0; k < i + j; k++) {
        a[l + k] = buf[k];
    }
}

void merge_sort0(vector<int>& a, int l, int r, vector<int>& buf) {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort0(a, l, m, buf);
    merge_sort0(a, m, r, buf);
    merge(a, l, m, r, buf);
}

void merge_sort(vector<int>& a) {
    int n = a.size();
    vector<int> buf(n);
    merge_sort0(a, 0, n, buf);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> buf(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(a);
    for (int el : a) cout << el << ' ';
}