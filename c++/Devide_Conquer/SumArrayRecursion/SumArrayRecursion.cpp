#include <iostream>
using namespace std;

// De quy tong mang
int sumArray(int A[], int n) {
	if (n <= 0) {
		return 0;
	}
	return (sumArray(A, n - 1) + A[n - 1]);
}

int main() {

    int n,i;
    int A[100];
    cin>>n;
    for(i=0;i<=n-1;i++)
       cin >>A[i];
    cout<<sumArray(A,n)<<endl;

    return 0;
}