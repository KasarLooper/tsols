#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(p);
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }

    vector<vector<int>> idx(n + 1, vector<int>());
    for (int i = 0; i < p; i++) {
        idx[a[i]].push_back(i);
    }

    unordered_set<int> floor;
    int cnt = 0;

    for (int i = 0; i < p; i++) {
        int cur = a[i];

        if (floor.find(cur) != floor.end()) {
            continue;
        }

        if (floor.size() >= k) {
            int rem = -1;
            int mx_j = -1;

            for (const auto& car : floor) {
                cout << car << ' ' << idx.size() << '\n';

                int cur_j = *lower_bound(
                    idx[car].begin(), idx[car].end(), i);

                if (cur_j > mx_j) {
                    mx_j = cur_j;
                    rem = car;
                }
            }

            floor.erase(rem);
        }

        floor.insert(cur);
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
