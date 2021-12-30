#include <iostream>
#include <string.h>
using namespace std;
 
#define MAX (100001)
#define MOD (1000000007)
 
long dp[MAX];
 
int main()
{
	int t, i, n;
 
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i < MAX; i++)
		dp[i] = (dp[i-1] % MOD * i % MOD) % MOD;
 
    cin >> t;
    for (i = 0; i < t; i++) {
		cin >> n;
    	cout << dp[n] << endl;
    }
    
    return 0;
}