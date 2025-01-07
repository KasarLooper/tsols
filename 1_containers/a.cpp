#include <iostream>

using namespace std;

bool valid_paranth(const string& s) {
    int opened = 0;
    for (char c : s) {
        if (c == '(')
            opened += 1;
        else if (opened < 1)
            return false;
        else
            opened -= 1;
    }
    return opened == 0;
}

int main() {
    string str;
    getline(cin, str);
    bool result = valid_paranth(str);
    if (result)
        cout << "yes";
    else
        cout << "no";
}