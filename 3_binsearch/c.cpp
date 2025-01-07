#include <iostream>
#include <iomanip>

using namespace std;

double sqrt0(double number) {
    double epsilon = 1e-10;
    double guess = number / 2.0;
    while (true) {
        double next = (guess + number / guess) / 2.0;
        if (std::abs(next - guess) < epsilon) {
            return next;
        }
        guess = next;
    }
}

int main() {
    double c;
    cin >> c;
    double l = 0, r = c;
    while (l + 1 < r) {
        double m = (l + r) / 2;
        if (m * m + sqrt0(m) >= c)
            r = m;
        else
            l = m;
    }
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (m * m + sqrt0(m) >= c)
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(15) << l << endl;
}