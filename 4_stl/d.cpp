#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string, set<string>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string sername, name, class_name, date;
        cin >> sername >> name >> class_name >> date;
        m[class_name].insert(sername + ' ' + name + ' ' + date);
    }

    for (auto class_name : m)
        for (auto student : class_name.second)
            cout << class_name.first << ' ' << student << '\n';
}