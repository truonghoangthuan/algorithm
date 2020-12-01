#include <stdio.h>

void swap(long long *x, long long *y) {
	long long tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

long long findPivot(long long a[], long long i, long long j) {
	long long firstkey = a[i];
	long long k = i + 1;

	while (k <= j && a[k] == firstkey)	k++;
	if (k > j)	return -1;
	if (a[k] > firstkey)	return k;
	return i;
}

long long partrition(long long a[], long long i, long long j, long long pivot) {
	long long L = i, R = j;

	while (L <= R)
	{
		while (a[L] < pivot)	L++;
		while (a[R] >= pivot)	R--;
		if (L < R)	swap(&a[L], &a[R]);
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

long long tichIthSoLonNhat(long long a[], long long i) {
	return (a[i] * a[i - 1] * a[i - 2]);
}

int main() {
	long long n; scanf("%lld", &n);
	long long mangTinh[2], mangKq[n];
	
	for (long long i = 0; i < n; i++) {
		long long a; scanf("%lld", &a);
		
		if (i < 2) {
			mangKq[i] = -1;
			mangTinh[i] = a;
			continue;
		}
		
		else if (i == 2) {
			mangTinh[i] = a;
		}
		
		else {
			quickSort(mangTinh, 0, 2);
			if (a > mangTinh[0])
				mangTinh[0] = a;
		}
		mangKq[i] = tichIthSoLonNhat(mangTinh, 2);
	}
	
	for (long long i = 0; i < n; i++) {
		printf("%lld\n", mangKq[i]);
	}
	
	return 0;
}
