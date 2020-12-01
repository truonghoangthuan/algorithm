#include<bits/stdc++.h>
using namespace std;

int max_sequence(int arr[], int n) { 
	int lis[n];

	lis[0] = 1; 

	for (int i = 1; i < n; i++ ) { 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	}

	return *max_element(lis, lis + n - 1); 
}

int main() { 
	int n = 10; // phần tử A[0] không sử dụng
	int A[] = {0, 2, -3, 4, 5, -6, 7, -8, -5, 3, 9};
	
	cout << max_sequence(A, n) << endl;

	return 0; 
}