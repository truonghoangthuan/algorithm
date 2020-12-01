#include <iostream>
using namespace std;

int main() {
    freopen("SumAtCellXY.inp", "r", stdin);
    int m, n; cin >> m >> n;
    int a[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (j != 0)
                a[i][j] += a[i][j - 1];
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        int sum = 0;

        for (int j = 0; j < x; j++)
            sum += a[j][y - 1];
        
        cout << sum << endl;
    }

    return 0;
}