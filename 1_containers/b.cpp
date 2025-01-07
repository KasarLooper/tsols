# include <iostream>
# include <vector>

using namespace std;

bool valid_paranth(string s) {
    vector<char> opened;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            opened.push_back(c);
        else if (opened.empty())
            return false;
        else if (c == ')' && opened.back() == '(' || c == ']' && opened.back() == '[' || c == '}' && opened.back() == '{')
            opened.pop_back();
        else
            return false;
    }
    return opened.empty();
}

int main() {
    string str;
    getline(cin, str);
    bool ans = valid_paranth(str);
    if (ans)
        cout << "yes";
    else
        cout << "no";
}
