#include <iostream>
#include <vector>

using namespace std;

// Подсчёт длины
int columns(long long w, vector<long long> a, int n) {
    int res = 1;
    long long d = 0;
    for (int i = 0; i < n; i++) {
        d += a[i];
        if (d > w) {
            d = 0;
            res += 1;
        }
        else
            d += 1;
    }
    return res;
}

int main() {
    // Считывание переменных, определение максимальных слов
    long long w;
    int n, m;
    cin >> w >> n >> m;
    vector<long long> a(n), b(m);
    long long max_a = 1, max_b = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        max_b = max(max_b, b[i]);
    }

    // Бин поиск
    long long l = max_a, r = w - max_b + 1;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (columns(mid, a, n) < columns(w - mid, b, m))
            r = mid;
        else
            l = mid;
    }

    // Ответ - часть рапорта с максимальной длиной
    long long ans = max(columns(r, a, n), columns(w - r, a, n));
    cout << ans << endl;
}