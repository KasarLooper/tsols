#include <iostream>
#include <iomanip>

using namespace std;

double f(double x, double a, double b, double c, double d) {
    return x * (x * (x * a + b) + c) + d;
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }

    double l = -1, r = 1;
    while (f(l, a, b, c, d) * f(r, a, b, c, d) >= 0) {
        l *= 2;
        r *= 2;
    }

    for (int i = 0; i < 50; i++) {
        double m = l + (r - l) / 2;
        if (f(m, a, b, c, d) < 0)
            l = m;
        else
            r = m;
    }

    cout << fixed << setprecision(15) << l + (r - l) / 2;
}