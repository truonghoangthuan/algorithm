#include <iostream>
using namespace std;

//Binary search
long long binarySearch(long long a[], long long key, long long start, long long end) {
	long long mid = (start + end) / 2;
	while (start != mid && mid != end) {
		if (a[mid] >= key)
			end = mid;
		else
			start = mid;
		mid = (start + end) / 2;
	}
	for (mid = start; mid <= end; mid++)
		if (a[mid] >= key)
			break;
	return mid;
}

int main() {
	freopen("TinhSoTem.inp", "r", stdin);
	long long n, q; cin >> n >> q;
	long long a[n], b[q], t[n];
	
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		t[i] = sum;
	}
	
	for (long long i = 0; i < q; i++) {
		cin >> b[i];
		long long index = binarySearch(t, b[i], 0, n);
		if (b[i] <= t[index])
			cout << index + 1 << endl;
	}
	
	return 0;
}
