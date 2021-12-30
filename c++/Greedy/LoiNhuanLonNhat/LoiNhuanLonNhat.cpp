#include <bits/stdc++.h>

using namespace std;

void swap(long long &x, long long &y) {
	long long tmp;
	tmp = x;
	x = y;
	y = tmp;
}

long long findPivot(long long a[], long long i, long long j) {
	long long firstkey = a[i];
	long long k = i + 1;
	
	while (k <= j && a[k] == firstkey)	k++;
	if (k>j)	return -1;
	if (a[k]>firstkey)	return k;
	return i;
}

long long partrition(long long a[], long long i, long long j, long long pivot) {
	long long L = i, R = j;

	while (L <= R)
	{
		while (a[L] >= pivot)	L++;
		while (a[R] < pivot)	R--;
		if (L < R)	swap(a[L], a[R]);
	}
	return L;
}

void quickSort(long long a[], long long i, long long j) {
	long long pivot, k;
	long long pivotIndex = findPivot(a, i, j);
	if (pivotIndex != -1)
	{
		pivot = a[pivotIndex];
		k = partrition(a, i, j, pivot);
		quickSort(a, i, k - 1);
		quickSort(a, k, j);
	}
}

void estimateProfit(const char *fileName) {
	freopen(fileName, "r", stdin);
	long long n; cin >> n;
	
	long long *a = new long long[n];
	long long *b = new long long[n];
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	quickSort(a, 0, n - 1);
	for (long long i = 0; i < n; i++) {
		cin >> b[i];
	}
	quickSort(b, 0, n - 1);
	
	long long loiNhuan = 0;
	for (long long i = 0; i< n; i++) {
		loiNhuan += a[i] * b[i];
	}
	cout << loiNhuan;
}

int main() {
	
	estimateProfit("Input\\VanGroup\\vg06.inp");
	
	return 0;
}
