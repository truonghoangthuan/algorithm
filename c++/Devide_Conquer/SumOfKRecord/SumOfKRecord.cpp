#include <iostream>
using namespace std;

//QuickSort
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
//============================//

void findkSum(const char* fileName) {
    freopen(fileName, "r", stdin);
	int n, q, A[100000], B[100000], i, j;

	cin >> n >> q;
	for (i = 0; i < n; i++)
		cin >> A[i];
	for (i = 0; i < q; i++)
		cin >> B[i];
	quickSort(A, 0, n - 1);

	for (i = 0; i < q; i++)
	{
		int sum = 0;
		j = 0;
		while (j < B[i])
		{
			sum = sum + A[n - 1 - j];
			j++;
		}
		cout << sum << endl;
	}
}

int main() {

    findkSum("SumOfKRecord.inp");

    return 0;
}