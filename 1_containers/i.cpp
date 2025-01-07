#include <iostream>
#include <deque>
#include <stack>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void from_path(deque<int>& path, stack<int>& lock, int cur) {
	int el = path.back();
	path.pop_back();
	while (!path.empty() && cur != el) {
		lock.push(el);
		el = path.back();
		path.pop_back();
	}
}

int from_lock(stack<int>& lock, int cur) {
	while (!lock.empty() && lock.top() == cur) {
		lock.pop();
		cur++;
	}
	return cur;
}

int main() {
	fastIO();

	int n;
	cin >> n;

	deque<int> path;
	stack<int> lock;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		path.push_front(x);
	}
	
	int cur = 1;
	while (!path.empty()) {
		from_path(path, lock, cur);
		cur = from_lock(lock, cur);
	}

	if (lock.empty()) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}
