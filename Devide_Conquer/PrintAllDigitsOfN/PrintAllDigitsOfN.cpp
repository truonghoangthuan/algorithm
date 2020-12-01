#include <iostream>
using namespace std;

void in_xuoi(int n) {
	if (n == 0)
		return;
	int lastDigit = n % 10;
	in_xuoi(n / 10);
	cout << lastDigit << " ";
}

int main() {
	
	in_xuoi(2354);
	
	return 0;
}
