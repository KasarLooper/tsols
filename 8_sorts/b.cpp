#include <iostream>
#include <vector>

using namespace std;

void move(vector<int>& a, int i) {
    if (i == 0 || a[i] >= a[i - 1]) return;
    swap(a[i], a[i - 1]);
    move(a, i - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) move(a, i);
    for (int el : a) cout << el << ' ';
}