#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    deque<long long> times;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long h, m;
        int imp;
        cin >> h >> m >> imp;
        long long t = h * 60 + m;

        while (times.size() > 0 && times.front() <= t) {
            times.pop_front();
        }

        if (times.size() > imp) {
            cout << h << ' ' << m << endl;
        }
        else if (times.empty()) {
            t += 20;
            times.push_back(t);
            cout << t / 60 << ' ' << t % 60 << endl;
        }
        else {
            t = times.back() + 20;
            times.push_back(t);
            cout << t / 60 << ' ' << t % 60 << endl;
        }
    }
}