#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int inf = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> st, res;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(st.back());
        st.push_back(i);
    }

    while (!res.empty()) {
        cout << res.back() << ' ';
        res.pop_back();
    }
}