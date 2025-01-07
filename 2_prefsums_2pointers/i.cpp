#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n1, n2, n3, n4;
    cin >> n1;
    vector<int> a(n1);
    for (int i = 0; i < n1; i++) cin >> a[i];
    sort(a.begin(), a.end());

    cin >> n2;
    vector<int> b(n2);
    for (int i = 0; i < n2; i++) cin >> b[i];
    sort(b.begin(), b.end());

    cin >> n3;
    vector<int> c(n3);
    for (int i = 0; i < n3; i++) cin >> c[i];
    sort(c.begin(), c.end());

    cin >> n4;
    vector<int> d(n4);
    for (int i = 0; i < n4; i++) cin >> d[i];
    sort(d.begin(), d.end());

    int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    int min_diff = max(max(a[i1], b[i2]), max(c[i3], d[i4])) -
                   min(min(a[i1], b[i2]), min(c[i3], d[i4]));
    int best1 = a[i1], best2 = b[i2], best3 = c[i3], best4 = d[i4];

    while (true) {
        vector<int> v;
        if (i1 < n1 - 1)
            v.push_back(a[i1]);
        if (i2 < n2 - 1)
            v.push_back(b[i2]);
        if (i3 < n3 - 1)
            v.push_back(c[i3]);
        if (i4 < n4 - 1)
            v.push_back(d[i4]);
        if (v.size() == 0)
            break;

        int increase = v[0];
        for (int i = 1; i < v.size(); i++)
            increase = min(increase, v[i]);

        if (increase == a[i1] && i1 < n1 - 1)
            i1 += 1;
        else if (increase == b[i2] && i2 < n2 - 1)
            i2 += 1;
        else if (increase == c[i3] && i3 < n3 - 1)
            i3 += 1;
        else if (increase == d[i4] && i4 < n4 - 1)
            i4 += 1;

        int diff = max(max(a[i1], b[i2]), max(c[i3], d[i4])) -
                   min(min(a[i1], b[i2]), min(c[i3], d[i4]));
        if (diff < min_diff) {
            min_diff = diff;
            best1 = a[i1], best2 = b[i2], best3 = c[i3], best4 = d[i4];
        }
    }

    cout << best1 << ' ' << best2 << ' ' << best3 << ' ' << best4 << endl;
}