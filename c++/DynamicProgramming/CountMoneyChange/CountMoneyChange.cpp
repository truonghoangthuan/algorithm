#include<bits/stdc++.h> 
  
using namespace std; 
  
long long countMoneyChange(long long S[], long long n, long long m) { 
    long long i, j, x, y;
    long long table[m + 1][n]; 

    for (i = 0; i < n; i++) 
        table[0][i] = 1;
    
    for (i = 1; i < m + 1; i++) 
    { 
        for (j = 0; j < n; j++) {
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            table[i][j] = x + y; 
        } 
    } 
    return table[m][n - 1]; 
}
  
int main() {
    freopen("CountMoneyChange.inp", "r", stdin);
    long long n, m; cin >> n >> m;
    long long arr[n];

    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << countMoneyChange(arr, n, m);

    return 0; 
} 