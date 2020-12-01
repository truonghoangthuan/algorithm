#include <iostream>
using namespace std;

long long min(long long a, long long b) {
	if (a < b)
		return a;
	return b;
}

void countOperations(const char *fileName) {
	freopen(fileName, "r", stdin);
	long long n, k; cin >> n >> k;
	
	long long cnt = 0;
	long long soDu = 0;
	for (long long i = 0; i < n; i++) {
		long long a; cin >> a;
		
		if (a % k == 0)
			continue;
		
		else if (a < k) {
			cnt += k - a;
		}
		
		else if (a > k) {
			soDu = a % k;
			cnt += min(soDu, k - soDu);
		}
	}
	cout << cnt;
}

int main() {
	
	countOperations("uc02New.inp");
	
	return 0;
}
