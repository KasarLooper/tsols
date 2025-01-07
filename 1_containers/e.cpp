#include <iostream>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;

class MinQueue {
private:
    deque<ll> q;
    queue<int> idx;

    deque<ll> mins;
    deque<int> midx;

    int cur_i = 0;

public:
    void push(ll x) {
        q.push_back(x);
        idx.push(cur_i);

        while (!mins.empty() && x < mins.back()) {
            mins.pop_back();
            midx.pop_back();
        }

        mins.push_back(x);
        midx.push_back(cur_i++);
    }

    ll pop() {
        ll deleting = q.front();

        if (mins.front() == deleting
            && idx.front() == midx.front()) {
            mins.pop_front();
            midx.pop_front();
        }

        q.pop_front();
        idx.pop();

        return deleting;
    }

    ll min() {
        return mins.front();
    }

    ll get(int i) {
        return q[i];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    MinQueue mq;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
            ll x;
            cin >> x;
            mq.push(x);
            break;
        case 2:
            cout << mq.pop() << '\n';
            break;
        case 3:
            int i;
            cin >> i;
            cout << mq.get(i - 1) << '\n';
            break;
        case 4:
            cout << mq.min() << '\n';
            break;
        default:
            break;
        }
    }
}
