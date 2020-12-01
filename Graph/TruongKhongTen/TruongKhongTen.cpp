#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TruongKhongTen.inp", "r", stdin);
    int t; cin >> t;
    
    for (int i = 0; i < t; i++) {
        int e; cin >> e;
        
        int a[10007];
        memset(a, 0, sizeof(a));

        int cnt = 0;
        for (int j = 0; j < e; j++) {
            int u, v; cin >> u >> v;

            if (a[u] == 0) {
                cnt++;
                a[u] = 1;
            }
    
            if (a[v] == 0) {
                cnt++;
                a[v] = 1;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}