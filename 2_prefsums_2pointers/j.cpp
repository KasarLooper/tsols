#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long* a = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long* pref = new long long[n + 1];
    pref[0] = 0;
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    int l = 1, r = n;
    int min_l = l, min_r = r;
    long long min_abs = abs(pref[n] - pref[l] - pref[r - 1]);
    while (r > l) {
        long long cur_sum = pref[r - 1] + pref[l];
        long long cur_abs = abs(pref[n] - cur_sum);

        if (cur_abs < min_abs) {
            min_abs = cur_abs;
            min_l = l;
            min_r = r;
        }

        if (cur_sum < pref[n]) l += 1;
        else if (cur_sum > pref[n]) r -= 1;
        else break;
    }

    cout << min_abs << ' ' << min_l << ' ' << min_r << ' ' << endl;
}