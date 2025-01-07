#include <iostream>
#include <stack>

using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	fastIO();

	int n;
	cin >> n;

	stack<pair<int, int>> st;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;

		if (st.empty())
			st.push(pair(c, 1));
		else {
			if (st.top().first == c)
				st.top().second++;
			else {
				if (st.top().second >= 3) {
					cnt += st.top().second;
					st.pop();
				}
				if (st.empty() || st.top().first != c)
					st.push(pair(c, 1));
				else
					st.top().second++;
			}
		}
	}

	if (st.top().second >= 3)
		cnt += st.top().second;

	cout << cnt;
}
