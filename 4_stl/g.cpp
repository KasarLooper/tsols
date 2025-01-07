#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void fastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
}

int main() {
        fastIO();

        int n, k, p;
        cin >> n >> k >> p;

        vector<int> usingg(n + 1, 0);
        vector<int> a(p);
        for (int i = 0; i < p; i++) {
                cin >> a[i];
                usingg[a[i]]++;
        }

        int cnt = 0;
        unordered_set<int> floor;
        for (int i = 0; i < p; i++) {
                cnt++;
                usingg[a[i]]--;
                if (floor.size() >= k) {
                        cnt++;
                        int rnd = -1;
                        for (auto el : floor) {
                                rnd = el;
                                if (usingg[el] <= 0) {
                                        rnd = -1;
                                        floor.erase(el);
					break;
                                }
                        }
                        if (rnd != -1)
                                floor.erase(rnd);
                }
                floor.insert(a[i]);
        }

        cout << cnt;
}
