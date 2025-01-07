#include <iostream>
#include <unordered_map>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

/*
int isqrt(int n) {
	int l = 0, r = n + 1;
	int m = (l + r) / 2;
	while (l + 1 < r) {
		if (m * m <= n)
			l = m;
		else
			r = m;
		m = (l + r) / 2;
	}
	return l;
}
*/

int main() {
	fastIO();

	int n;
	cin >> n;
	
	unordered_map<int, pair<int, int>> sqsum;
	for (int a = 0; a * a <= n; a++) {
		for (int b = 0; a * a + b * b <= n; b++) {
			sqsum[a * a + b * b] = {a, b};
		}
	}
	
	for (auto el : sqsum) {
		int x = el.first;
		int y = n - x;
		if (sqsum.find(y) != sqsum.end()) {
			auto el2 = sqsum[y];
			cout << el.second.first << ' ' << el.second.second << ' ' << el2.first << ' ' << el2.second << '\n';
			break;
		}
	}
}
