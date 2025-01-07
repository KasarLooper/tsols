#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	fastIO();

	int n;
	cin >> n;

	set<int> free;
	for (int i = 1; i <= 100000; i++) {
		free.insert(i);
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < 0) {
			free.insert(-a);
		}
		else {
			auto it = lower_bound(free.begin(), free.end(), a);
			cout << *it << '\n';
			if (*it == *free.rbegin())
				free.insert(*it + 1);
	    		free.erase(it);
		}
	}
}
