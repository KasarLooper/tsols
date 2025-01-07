#include <iostream>

using namespace std;

int squares(int a, int b) {
    if (b > a)
        swap(a, b);
    if (a % b == 0)
        return a / b;
    return a / b + squares(a % b, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    cout << squares(a, b);
}