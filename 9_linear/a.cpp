#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int inf = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> els, idx, mins;
    for (int i = 0; i < k; i++) {
        els.push_back(a[i]);
        while (!mins.empty() && mins.back() > a[i]) {
            mins.pop_back();
            idx.pop_back();
        }
        mins.push_back(a[i]);
        idx.push_back(i);
    }
    cout << mins.front() << ' ';

    for (int i = k; i < n; i++) {
        // Push
        els.push_back(a[i]);
        while (!mins.empty() && mins.back() > a[i]) {
            mins.pop_back();
            idx.pop_back();
        }
        mins.push_back(a[i]);
        idx.push_back(i);

        // Pop
        int j = i - k;
        int x = els.front();
        els.pop_front();
        if (mins.front() == x && idx.front() == j) {
            mins.pop_front();
            idx.pop_front();
        }

        cout << mins.front() << ' ';
    }
}