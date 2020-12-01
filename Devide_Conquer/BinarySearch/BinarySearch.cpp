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

//Binary search
int binarySearch(int a[], int key, int start, int end) {
	int mid = (start + end) / 2;
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

void search(const char *fileName) {
	freopen(fileName, "r", stdin);
	int n, m; cin >> n >> m;
	int a[n], b[m];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quickSort(a, 0, n - 1);

	for (int i = 0; i < m; i++) {
		cin >> b[i];
		int index = binarySearch(a, b[i], 0, n);
		if (b[i] == a[index])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
}

int main() {
	
	search("BinarySearch.inp");
		
	return 0;
}