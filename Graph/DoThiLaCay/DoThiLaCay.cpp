#include <iostream>

using namespace std;

void isTree(int n) {
	int i;
	int a[n];
	int max = -1;
	bool flag = false;
	
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
		if (a[i] == 1)
			flag = true;
	}
	
	if (!flag) {
		cout << "NO";
		return;
	}
	
	int nodeArr[n];
	for (i = 0; i <= max; i++) {
		nodeArr[i] = 0;
	}
	
	for (i = 0; i < n; i++) {
		int bac = a[i];
		nodeArr[bac] += 1;
	}
	
	int sum = 0;
	for (i = 0; i <= max; i++) {
		sum += (i - 2) * nodeArr[i];
	}
	
	if (sum == -2)
		cout << "YES";
	else
		cout << "NO";
}

int main() {
	int n;
	
	cin >> n;
	isTree(n);
	
	return 0;
}
