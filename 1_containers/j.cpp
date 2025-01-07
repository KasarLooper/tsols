#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    deque<int> first, second;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int x;
            cin >> x;
            second.push_back(x);
            if (second.size() > first.size()) {
                first.push_back(second.front());
                second.pop_front();
            }
        }
        else if (op == '-') {
            cout << first.front() << endl;
            first.pop_front();
            if (second.size() > first.size()) {
                first.push_back(second.front());
                second.pop_front();
            }
        }
        else if (op == '*') {
            int x;
            cin >> x;
            if (first.size() == second.size())
                first.push_back(x);
            else
                second.push_front(x);
        }
    }
}