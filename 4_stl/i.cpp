#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<int> free;
	for (int i = 1; i <= 2e5; i++) {
		free.insert(i);
	}

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > 0) {
			auto it = free.lower_bound(x); // Use lower bound from set for eficiency!!!
			cout << *it << '\n';
			free.erase(it);
		}
		else {
			free.insert(-x);
		}
	}
}
