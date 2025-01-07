#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> left, right;
    for (int a = 1; a * a <= n; a++) {
        if (n % a == 0) {
            int b = n / a;
            left.push_back(a);
            if (a != b)
                right.push_back(b);
        }
    }

    cout << left.size() + right.size() << '\n';
    for (int i : left)
        cout << i << ' ';
    for (int i = right.size() - 1; i >= 0; i--)
        cout << right[i] << ' ';
}