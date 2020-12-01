#include <iostream>
using namespace std;

//MergeSort
void merge(int a[], int low, int mid, int high) {
	int firstHalve = mid - low + 1;
	int secondHalve = high - mid;
	
	int *L = (int*)malloc(firstHalve*sizeof(int));
	int *R = (int*)malloc(secondHalve*sizeof(int));
	
	for (int i = 0; i < firstHalve; i++)
		L[i] = a[low + i];
		
	for (int i = 0; i < secondHalve; i++)
		R[i] = a[mid + i + 1];
	
	int i = 0, j = 0, k = low;
	while (i < firstHalve && j < secondHalve)
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	while (i < firstHalve)
		a[k++] = L[i++];
	while (j < secondHalve)
		a[k++] = R[j++];
}

void mergeSort(int a[], int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main() {
    int n; cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}