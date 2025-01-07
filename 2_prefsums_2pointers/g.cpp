Исходный код
# include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    long long i = 1, j = 1;
    long long ans = 1;
    long long ai = i * i;
    long long bi = j * j * j;

    for (int k = 0; k < x; k++) {
        if (ai == bi) {
            ans = ai;
            i += 1;
            j += 1;
            ai = i * i;
            bi = j * j * j;
        }
        else if (ai > bi) {
            ans = bi;
            j += 1;
            bi = j * j * j;
        }
        else {
            ans = ai;
            i += 1;
            ai = i * i;
        }
    }
    cout << ans;
}