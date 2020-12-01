#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

void SieveofEratosthenes(long long n) {
	bool A[n + 1];
	memset (A, true, sizeof(A));
	
	if (n < 2) return;
	for (long long i = 2; i * i < n; i++) {
		if (A[i] == true) {
			for (long long j = i * 2; j <= n; j += i) {
				A[j] = false;
			}
		}
	}
	
	for (long long i = n; i >= 2; i--){
		if (A[i]) {
			cout << i << endl;
			break;
		}
	}
}

int main() {
	long long n;
	
	cin >> n;
	SieveofEratosthenes(n);
	
	return 0;
}
