#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<vector<ll>>> a(n,
		vector<vector<ll>>(m,
			vector<ll>(k, 0)));
	for (int z = 0; z < n; z++) {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < k; x++) {
				cin >> a[z][y][x];
			}
		}
	}

	vector<vector<vector<ll>>> pref(n + 1,
		vector<vector<ll>>(m + 1,
			vector<ll>(k + 1, 0)));
	for (int z = 0; z < n; z++) {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < k; x++) {
				pref[z + 1][y + 1][x + 1] = a[z][y][x]
					+ pref[z][y + 1][x + 1]
					+ pref[z + 1][y][x + 1]
					+ pref[z + 1][y + 1][x]

					- pref[z + 1][y][x]
					- pref[z][y + 1][x]
					- pref[z][y][x + 1]

					+ pref[z][y][x];
			}
		}
	}

	int q;
	cin >> q;

	ll sum;
	int lx, ly, lz, rx, ry, rz;
	for (int _ = 0; _ < q; _++) {
		cin >> lz >> ly >> lx >> rz >> ry >> rx;
		sum = pref[rz][ry][rx]
			- pref[rz][ry][lx - 1]
			- pref[rz][ly - 1][rx]
			- pref[lz - 1][ry][rx]

			+ pref[rz][ly - 1][lx - 1]
			+ pref[lz - 1][ry][lx - 1]
			+ pref[lz - 1][ly - 1][rx]

			- pref[lz - 1][ly - 1][lx - 1];

		cout << sum << ' ';
	}
}
