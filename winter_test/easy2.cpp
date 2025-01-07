#include <iostream>
#include <vector>

using namespace std;

int ways(int x, int y) {
	if (x < 1 || x > 8)
		return 0;
	if (y >= 8)
		return 1;
	return ways(x - 1, y + 1) + ways(x + 1, y + 1);
}

int main() {
	int x, y;
	cin >> x >> y;
	
	cout << ways(x, y);
}
