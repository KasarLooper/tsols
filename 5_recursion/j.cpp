#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

void gen(vector<char>& pref, stack<char>& open, int n) {
	if (pref.size() >= n) {
		if (open.size() == 0) {
			for (auto el : pref)
				cout << el; 
			cout << '\n';
		}
		return;
	}

	if (n - pref.size() < open.size())
		return;

	pref.push_back('(');
	open.push('(');
	gen(pref, open, n);
	pref.pop_back();
	open.pop();

	pref.push_back('[');
	open.push('[');
	gen(pref, open, n);
	pref.pop_back();
	open.pop();

	if (!open.size() == 0 && open.top() == '(') {
		pref.push_back(')');
		open.pop();
		gen(pref, open, n);
		pref.pop_back();
		open.push('(');
	}

	if (!open.size() == 0 && open.top() == '[') {
		pref.push_back(']');
		open.pop();
		gen(pref, open, n);
		pref.pop_back();
		open.push('[');
	}

}

int main() {
	fastIO();

	int n;
	cin >> n;

	vector<char> pref;
	stack<char> open;

	gen(pref, open, n);
}
