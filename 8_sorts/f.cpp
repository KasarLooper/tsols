#include <iostream>
#include <vector>
#include <random>

using namespace std;

void qsort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, n - 1);
    int m = distrib(gen);
    int mid = arr[m];
    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        if (arr[i] < mid) left.push_back(arr[i]);
        else if (i != m) right.push_back(arr[i]);
    }
    qsort(left);
    qsort(right);
    for (int i = 0; i < n; i++) {
        if (i < left.size()) arr[i] = left[i];
        else if (i == left.size()) arr[i] = mid;
        else arr[i] = right[i - left.size() - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    qsort(a);
    for (int el : a) cout << el << ' ';
}