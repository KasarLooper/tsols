# include <iostream>
# include <vector>

using namespace std;

class MinStack {
private:
    vector<long long> base;
    vector<long long> mins;

public:
    void push(long long x) {
        base.push_back(x);
        long long min_el = x;
        if (!mins.empty() && mins.back() < x)
            min_el = mins.back();
        mins.push_back(min_el);
    }

    long long pop() {
        long long res = base.back();
        base.pop_back();
        mins.pop_back();
        return res;
    }

    long long min() {
        return mins.back();
    }
};

int main() {
    MinStack ms;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            long long x;
            cin >> x;
            ms.push(x);
        }
        else if (op == 2) {
            cout << ms.pop() << endl;
        }
        else {
            cout << ms.min() << endl;
        }
    }
}
