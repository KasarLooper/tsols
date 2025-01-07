#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> base;
    vector<int> mins;

public:
    void push(int x) {
        base.push_back(x);
        int min_el = x;
        if (!mins.empty() && mins.back() < x)
            min_el = mins.back();
        mins.push_back(min_el);
    }

    int pop() {
        int res = base.back();
        base.pop_back();
        mins.pop_back();
        return res;
    }

    int min() {
        return mins.back();
    }

    bool empty() {
        return base.empty();
    }
};

class MinQueue {
private:
    MinStack in, out;

public:
    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    int min() {
        if (in.empty()) return out.min();
        else if (out.empty()) return in.min();
        return std::min(in.min(), out.min());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    MinQueue mq;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        mq.push(x);
    }
    cout << mq.min() << ' ';

    for (int i = 0; i < n - k; i++) {
        int x;
        cin >> x;
        mq.pop();
        mq.push(x);
        cout << mq.min() << ' ';
    }
}