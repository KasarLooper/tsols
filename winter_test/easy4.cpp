#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    int q;
    cin >> q;
    cin.ignore();

    vector<ll> pref(1, 0);
    for (int i = 0; i < q; i++) {
        string in;
        getline(cin, in);

        char op = in[0];
        if (op == '-') {
           
            if (pref.size() >= 2) {
                cout << pref[pref.size() - 1] - pref[pref.size() - 2] << endl;
		pref.pop_back();
            }

        } else {
            ll n = stoll(in.substr(1));
            if (op == '?') { 
                if (pref.size() > n) {
                    cout << pref[pref.size() - 1] - pref[pref.size() - 1 - n] << endl;
                }            
            } else { 
                pref.push_back(pref.back() + n);
            }
        }
    }

    return 0;
}

