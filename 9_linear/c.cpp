#include <iostream>
#include <vector>
#include <deque>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    vector<int> left(n), right(n);
    deque<int> st1, st2;

    for (int i = n - 1; i >= 0; i--) {
        while (!st1.empty() && h[st1.back()] >= h[i])
            st1.pop_back();
        if (st1.empty())
            right[i] = n;
        else
            right[i] = st1.back();
        st1.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        while (!st2.empty() && h[st2.back()] >= h[i])
            st2.pop_back();
        if (st2.empty())
            left[i] = -1;
        else
            left[i] = st2.back();
        st2.push_back(i);
    }

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll width = right[i] - left[i] - 1;
        if (width > 0) {
            ll cur = h[i] * width;
            if (cur > mx)
                mx = cur;
        }
    }

    cout << mx << '\n';
}