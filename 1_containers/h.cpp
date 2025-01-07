#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int q;
    cin >> q;
    deque<long long> nums;
    deque<long long> ns;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            long long x, c;
            cin >> x;
            cin >> c;
            nums.push_back(x);
            ns.push_back(c);
        }
        else {
            long long ans = 0;
            long long c;
            cin >> c;
            while (c > 0) {
                if (c < ns.front()) {
                    long long first = ns.front() - c;
                    ns.pop_front();
                    ns.push_front(first);
                    ans += c * nums.front();
                    c = 0;
                }
                else {
                    ans += ns.front() * nums.front();
                    c -= ns.front();
                    ns.pop_front();
                    nums.pop_front();
                }
            }
            cout << ans << endl;
        }
    }
}