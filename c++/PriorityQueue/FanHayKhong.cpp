#include <stdio.h>

void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int findPivot(int a[], int i, int j) {
	int firstkey = a[i];
	int k = i + 1;

	while (k <= j && a[k] == firstkey)	k++;
	if (k > j)	return -1;
	if (a[k] > firstkey)	return k;
	return i;
}

int partrition(int a[], int i, int j, int pivot) {
	int L = i, R = j;

	while (L <= R)
	{
		while (a[L] < pivot)	L++;
		while (a[R] >= pivot)	R--;
		if (L < R)	swap(&a[L], &a[R]);
	}
	return L;
}

void quickSort(int a[], int i, int j) {
	int pivot, k;
	int pivotIndex = findPivot(a, i, j);
	if (pivotIndex != -1)
	{
		pivot = a[pivotIndex];
		k = partrition(a, i, j, pivot);
		quickSort(a, i, k - 1);
		quickSort(a, k, j);
	}
}

int main() {
	int n; scanf("%d", &n);
	int a[n];
	
	for (int i =0 ; i < n; i++)
		scanf("%d", &a[i]);
	quickSort(a, 0, n - 1);
	
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int k;
		char smallLarge;
		scanf("%d%c", &k, &smallLarge);
		scanf("%c", &smallLarge);
		
		int index;
		if (smallLarge == 'S')
			index = k - 1;
			
		if (smallLarge == 'L')
			index = n - k;
			
		printf("%d\n", a[index]);
	}
		
	return 0;
}
