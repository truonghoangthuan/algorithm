#include <iostream>
using namespace std;

int findMaxPathOfMaze(int n, int m) {
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;
            
            else if (i == 0 && j > 0)
                a[i][j] += a[i][j - 1];
            
            else if (i > 0 && j == 0)
                a[i][j] += a[i - 1][j];
            
            else
                a[i][j] += max(a[i - 1][j], max(a[i - 1][j - 1], a[i][j - 1]));
        }
    }
    return a[n - 1][m - 1];
}

int main() {
    freopen("FindMaxPathOfMaze.inp", "r", stdin);
    int n, m; cin >> n >> m;
    
    cout << findMaxPathOfMaze(n, m) << endl;

    return 0;
}