#include <iostream>
#include <vector>

using namespace std;

unsigned long long merge(vector<unsigned long long>& arr, unsigned long long l, unsigned long long m, unsigned long long r, vector<unsigned long long>& buf) {
    unsigned long long i = l;
    unsigned long long j = m;
    unsigned long long k = 0;
    unsigned long long cnt = 0;

    while (i < m && j < r) {
        if (arr[i] <= arr[j]) {
            buf[k++] = arr[i++];
        } else {
            buf[k++] = arr[j++];
            cnt += (m - i);
        }
    }

    while (i < m) {
        buf[k++] = arr[i++];
    }

    while (j < r) {
        buf[k++] = arr[j++];
    }

    for (unsigned long long p = 0; p < k; p++) {
        arr[l + p] = buf[p];
    }

    return cnt;
}

unsigned long long merge_sort(vector<unsigned long long>& arr, unsigned long long l, unsigned long long r, vector<unsigned long long>& buf) {
    if (r - l <= 1)
        return 0;

    unsigned long long m = (l + r) / 2;
    unsigned long long a = merge_sort(arr, l, m, buf);
    unsigned long long b = merge_sort(arr, m, r, buf);

    return merge(arr, l, m, r, buf) + a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n, l;
    cin >> n >> l;
    vector<unsigned long long> a(n);
    unsigned long long x;
    for (unsigned long long i = 0; i < n; i++) {
        cin >> x;
        a[i] = i + l * x;
    }

    vector<unsigned long long> buf(n);
    cout << merge_sort(a, 0, n, buf) << '\n';

    return 0;
}