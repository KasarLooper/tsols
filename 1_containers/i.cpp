#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	queue<int> path;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		path.push(x);
	}

	vector<pair<int, int>> res;
	stack<int> dead;

	int dest = 1;
	while (!path.empty()) {
		int moved = 0;
		for (; (dead.empty() || dead.top() != dest) &&
			!path.empty(); moved++) {
			dead.push(path.front());
			path.pop();
		}
		if (moved != 0) {
			res.emplace_back(1, moved);
		}

		moved = 0;
		for (; !dead.empty() && dead.top() == dest; moved++) {
			dead.pop();
			dest++;
		}
		if (moved != 0) {
			res.emplace_back(2, moved);
		}
	}

	if (dead.empty()) {
		cout << res.size() << '\n';
		for (auto el : res) {
			cout << el.first << ' ' << el.second << '\n';
		}
	}
	else {
		cout << "0\n";
	}
}
