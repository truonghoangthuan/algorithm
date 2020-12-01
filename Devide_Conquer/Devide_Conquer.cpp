#include <iostream>

using namespace std;

// Tim doan co tong lon nhat
int max(int a, int b) {
	return (a > b) ? a : b;
}

int max_sum(int A[], int n) {
	int i, sum, ans;

	sum = ans = 0;
	for (i = 0; i <= n; i++) {
		sum += A[i];
		ans = max(sum, ans);
		if (sum < 0) {
			sum = 0;
		}
	}
	return ans;
}

// De quy tim Max
/*int getMax(int A[], int n) {
	if (n == 1)
	{
		return A[0];
	};
	return max(A[n - 1], getMax(A, n - 1));
}

// Sap xep theo modulo k
int findPivotModulo(int a[], int i, int j, int key) {
	int firstkey = a[i]%key;
	int k = i + 1;

	while (k <= j && a[k]%key == firstkey)	k++;
	if (k > j)	return -1;
	if (a[k]%key > firstkey)	return k;
	return i;
}

int partritionModulo(int a[], int i, int j, int pivot, int key) {
	int L = i, R = j;

	while (L <= R)
	{
		while (a[L] % key < pivot)	L++;
		while (a[R] % key >= pivot)	R--;
		if (L < R)	swap(a[L], a[R]);
	}
	return L;
}

void quickSortModulo(int a[], int i, int j, int key) {
	int pivot, k;
	int pivotIndex = findPivotModulo(a, i, j, key);
	if (pivotIndex != -1)
	{
		pivot = a[pivotIndex]%key;
		k = partritionModulo(a, i, j, pivot, key);
		quickSortModulo(a, i, k - 1, key);
		quickSortModulo(a, k, j, key);
	}
}*/

void insertSort(int a[], int n, int key) {
	int i, j;
	for (i = 0; i < n; i++) {
		j = i;
		while (j > 0 && a[j] % key < a[j - 1] % key) {
			swap(a[j], a[j - 1]);
			j = j - 1;
		}
	}
}

void moduloSort(/*const char* fileName*/) {
	int n, k, A[10000], i;
	//freopen(fileName, "r", stdin);

	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	insertSort(A, n, k);
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}

// De quy in so mu cua 2
void print2Power(int n) {
	if (n == 0)
	{
		cout << 1;
		return;
	};
	int sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= 2;
		cout << sum << " ";
	}
}

int main() {

	moduloSort();

	return 0;
}