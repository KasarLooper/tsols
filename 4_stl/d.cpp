#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

struct Student {
	string name, sirname, clas, birth;
	
	bool operator < (const Student& other) const {
		if (clas != other.clas) {
			int num = stoi(clas);
			int other_num = stoi(other.clas);
			if (num != other_num)
				return num < other_num;
			return clas < other.clas;
		}
		return sirname < other.sirname;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Student> students;
	for (int i = 0; i < n; i++) {
		Student cur;
		cin >> cur.sirname >> cur.name 
			>> cur.clas >> cur.birth;
		students.push_back(cur);
	}

	sort(students.begin(), students.end());

	for (auto el : students) {
		cout << el.clas << ' ' << el.sirname << ' '
			<< el.name << ' ' << el.birth << '\n';
	}
}
