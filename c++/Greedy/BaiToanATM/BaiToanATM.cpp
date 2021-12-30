#include <iostream>
using namespace std;

int main (){
	int n, x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;
	int tiendu = 0;
	
	cin >> n;
	
	if (n % 10 != 0) {
		cout << "KHONG RUT DUOC";
	}
	
	x1 = n / 500000;
	if (x1 != 0)
		cout << "500000 VND: " << x1 << endl;
	tiendu = n - (x1 * 500000);
	
	x2 = tiendu / 200000;
	if (x2 != 0)
		cout << "200000 VND: " << x2 << endl;
	tiendu = tiendu - (x2 * 200000);
	
	x3 = tiendu / 100000;
	if (x3 != 0)
		cout << "100000 VND: " << x3 << endl;
	tiendu = tiendu - (x3 * 100000);
	
	x4 = tiendu / 50000;
	if (x4 != 0)
		cout << "50000 VND: " << x4 << endl;
	tiendu = tiendu - (x4 * 50000);
	
	x5 = tiendu / 20000;
	if (x5 != 0)
		cout << "20000 VND: " << x5 << endl;
	tiendu = tiendu - (x5 * 20000);
	
	x6 = tiendu / 10000;
	if (x6 != 0)
		cout << "10000 VND: " << x6 << endl;
	tiendu = tiendu - (x6 * 10000);
	
	return 0;
}
