#include <iostream>
#include <vector>

using namespace std;

int perform_op(long long a, long long b, long long op) {
    switch (op) {
        case 1:
            return a + b;
            break;
        case 2:
            return a - b;
            break;
        case 3:
            return a * b;
            break;
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> last;
    for (long long i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            long long x;
            cin >> x;
            last.push_back(x);

        }
        else {
            long long b = last.back();
            last.pop_back();
            long long a = last.back();
            last.pop_back();
            last.push_back(perform_op(a, b, op));
        }
    }
    cout << last.back();
}
