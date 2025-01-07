#include <iostream>
#include <vector>

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

    long long get(int i) {
        return base[i];
    }

    int size() {
        return base.size();
    }
};

class MinQueue {
private:
    MinStack in, out;

public:
    void push(long long x) {
        in.push(x);
    }

    long long pop() {
        if (out.size() == 0) {
            while (in.size() > 0) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    long long min() {
        if (in.size() == 0) return out.min();
        if (out.size() == 0) return in.min();
        long long a = in.min();
        long long b = out.min();
        if (a <= b) return a;
        return b;
    }

    long long get(int i) {
        int n = in.size();
        int m = out.size();
        if (n == 0 || i < m) return out.get(m - 1 - i);
        return in.get(i + m);
    }
};

int main() {
    int q;
    cin >> q;
    MinQueue mq;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        switch (op)
        {
            case 1:
                long long x;
                cin >> x;
                mq.push(x);
                break;
            case 2:
                cout << mq.pop() << endl;
                break;
            case 3:
                int i;
                cin >> i;
                cout << mq.get(i - 1) << endl;
                break;
            case 4:
                cout << mq.min() << endl;
                break;
            default:
                break;
        }
    }
}