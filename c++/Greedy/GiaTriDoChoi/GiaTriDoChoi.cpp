#include <bits/stdc++.h>
using namespace std;

struct Toy
{
	int value;
    int box;
};

bool cmp (Toy a, Toy b) {
	return (a.value > b.value);
}

int main() {
//	freopen("GiaTriDoChoi.inp", "r", stdin);
	int n, m; cin >> n >> m;
	Toy toys[n];
	
	for (int i = 0; i < n; i++)
		cin >> toys[i].value >> toys[i].box;
	sort(toys, toys + n, cmp);
		
	int a[m];
	memset(a, 0, sizeof(a));
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int index = toys[i].box;
		if (a[index - 1] == 0) {
			sum += toys[i].value;
			a[index - 1] = 1;
		}
	}
	cout << sum;
	
	return 0;
}
