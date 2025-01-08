#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<deque<int>> grouped(k + 1, deque<int>());
	int contains = 0;

	int cnt = 0;
	vector<vector<int>>	kits;

	for (int i = 0; i < n; i++) {
		if (grouped[a[i]].empty())
			contains++;
		grouped[a[i]].push_back(i);

		if (i > m) {
			int rem = i - m - 1;
			if (!grouped[a[rem]].empty() &&
				 grouped[a[rem]].front() == rem) {
				grouped[a[rem]].pop_front();

				if (grouped[a[rem]].empty())
					contains--;
			}
		}

		if (contains == k) {
			cnt++;
			kits.push_back(vector<int>());
			for (int j = 1; j <= k; j++) {
				kits.back().push_back(grouped[j].front());
				grouped[j].pop_front();

				if (grouped[j].empty())
					contains--;
			}
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		for (int el : kits[i])
			cout << (el + 1) << ' ';
		cout << '\n';
	}
}
