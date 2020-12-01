#include <iostream>
using namespace std;

// Thap HN
void move(int n, char A, char B, char C) {
	if (n == 0)
		return;
	move(n - 1, A, C, B);
	printf("%c -> %c\n", A, B);
	move(n - 1, C, B, A);
}

int main() {
	int n; cin >> n;

	move(n, 'A', 'B', 'C');

    return 0;
}