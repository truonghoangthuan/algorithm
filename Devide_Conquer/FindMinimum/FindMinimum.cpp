#include <iostream>
using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}

int getMin(int a[], int n) {
	if (n == 1)
		return a[0];
	return min(a[n - 1], getMin(a, n - 1));
}

int main() {
	int n; cin >> n;
	int a[n];
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << getMin(a, n); 
	
	return 0;
}
