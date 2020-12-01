#include <iostream>
using namespace std;

void swap(int& x, int& y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
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
		if (L < R)	swap(a[L], a[R]);
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
	freopen("QuickSort04.inp", "r", stdin);
	int n; cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	return 0;
}
