#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	fastIO();

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int l = 0;
	vector<int> trees(k + 1, 0);
	trees[a[0]] = 1;
	int cnt = 1;

	int m = n;
	int ml = 0, mr = n - 1;
	for (int r = 1; r < n; r++) {
		if (trees[r] == 0)
			cnt++;
		trees[r]++;
		for (; trees[a[l]] > 1; l++)
			trees[a[l]]--;
		if (cnt < k)
			continue;
		int len = r - l + 1;
		if (len < m) {
			cout << l << ' ' << r << ' ' << len << '\n';
			m = len;
			ml = l;
			mr = r;
		}	
	}

	cout << ml + 1 << ' ' << mr + 1;
}
