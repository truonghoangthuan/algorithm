#include <iostream>
using namespace std;

void pascalTriangle(long long n) {
    long long a[n + 1][n + 1];
    for (long long i = 0; i <= n; i++)
        a[i][i] = 0;

    for (long long i = 0; i <= n; i++) {
        for (long long j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i][j - 1] * (i - j + 1) / j;
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    long long n; cin >> n;

    pascalTriangle(n);

    return 0;
}