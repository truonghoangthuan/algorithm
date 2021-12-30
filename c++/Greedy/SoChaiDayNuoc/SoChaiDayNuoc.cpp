#include <iostream>
using namespace std;

//=========QuickSort==========//
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

void solve(const char *fileName) {
	freopen(fileName, "r", stdin);
	int t; cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n, x; cin >> n >> x;
		int a[n];
		for (int j = 0; j < n; j++)
			cin >> a[j];
		quickSort(a, 0, n - 1);
		
		int j = 0;
		while (a[j] <= x && j < n) {
			x -= a[j];
			j++;
		}
		cout << j << endl;
	}
}

int main() {
	
	solve("SoChaiDayNuoc.inp");
	
	return 0;
}
