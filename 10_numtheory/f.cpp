#include <iostream>
#include <vector>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<int, int> solve(int a, int b, int c) {
    if (a == 0 && b == 0)
        return {0, 0};
    else if (a == 0)
        return {0, c / b};
    else if (b == 0)
        return {c / a, 0};

    pair<int, int> xy = solve(b % a, a, c);
    int x0 = xy.first;
    int y0 = xy.second;

    int x = y0 - b / a * x0;
    int y = x0;

    return {x, y};
}

int main() {
    fastIO();

    int a, b, c;
    cin >> a >> b >> c;

    int g = gcd(a, b);

    if (c % g != 0) {
        cout << "Impossible";
        return 0;
    }

    pair<int, int> res = solve(a, b, c);
    cout << g << ' ' << res.first << ' ' << res.second;
}