#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream in("./dictionary.in");
    ofstream out("./dictionary.out");
    map<string, set<string>> dict;
    string s, english;
    while (getline(in, s)) {
        istringstream iss(s);
        getline(iss, english, ' ');
        iss.ignore(2);
        while (getline(iss, s, ',')) {
            dict[s].insert(english);
            iss.ignore(1);
        }
        iss >> s;
        dict[s].insert(english);
    }

    out << dict.size() << '\n';
    for (auto& pair : dict) {
        string latin = pair.first;
        set<string> eng = pair.second;

        out << latin << " - ";
        for (auto it = eng.begin(); it != eng.end(); it++) {
            if (it != eng.begin()) out << ", ";
            out << *it;
        }
        out << '\n';
    }
}