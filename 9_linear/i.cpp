#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s = a[0];
    int l = 0, r = 0;
    int mn = s, ml = l, mr = r;
    for (int i = 1; i < n; i++) {
        if (s > 0) {
            s = 0;
            l = i;
            r = i - 1;
        }
        s += a[i];
        r += 1;

        if (r - l + 1 >= n - 1) {
            s -= a[l];
            l += 1;
        }

        if (s < mn) {
            mn = s;
            ml = l;
            mr = r;
        }
    }

    if (mn > 0) {
        //throw exception();
        if (ml != 0)
            cout << ml << ' ' << (mr - ml + 1) << ' ' << (n - mr - 1);
        else {
            int n1 = mr + 1;
            int n2 = 1;
            int n3 = n - n1 - n2;
            cout << n1 << ' ' << n2 << ' ' << n3;
        }
    }
    else if (ml == 0) {
        int sum = 0;
        for (int i = mr + 1; i < n; i++)
            sum += a[i];

        int s1 = 0;
        int s2;
        for (int i = mr + 1; i < n; i++) {
            s1 += a[i];
            s2 = sum - s1;

            if (s1 > 0 && s2 > 0) {
                cout << (mr + 1) << ' ' << (i - mr) << ' ' << (n - i - 1);
                return 0;
            }
        }

        cout << 0;
    }
    else if (mr == n - 1) {
        int sum = 0;
        for (int i = 0; i < ml; i++)
            sum += a[i];

        int s1 = 0;
        int s2;
        for (int i = 0; i < ml; i++) {
            s1 += a[i];
            s2 = sum - s1;

            if (s1 > 0 && s2 > 0) {
                cout << (i + 1) << ' ' << (ml - i) << ' ' << (mr - ml + 1);
                return 0;
            }
        }

        cout << 0;
    }
    else {
        int sum = 0;
        for (int i = 0; i < ml; i++)
            sum += a[i];
        if (sum <= 0) {
            cout << 0;
            return 0;
        }
        sum = 0;
        for (int i = mr + 1; i < n; i++)
            sum += a[i];
        if (sum <= 0) {
            cout << 0;
            return 0;
        }

        cout << ml << ' ' << (mr - ml + 1) << ' ' << (n - mr - 1);
    }
}