#include <stdio.h>
#include <malloc.h>

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

int main() {
//	freopen("FanHayKhong.inp", "r", stdin);
	int n; scanf("%d", &n);
	int a[n];
	
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergeSort(a, 0, n - 1);
	
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int cauHoi; scanf("%d", &cauHoi);
		
		int viTri = binarySearch(a, cauHoi, 0, n);
		printf("%d\n", viTri + 1);
	}
	
	return 0;
}
