#include <iostream>

using namespace std;

long long compareMax(long long a, long long b) {
	if (a > b) 
		return a;
	return b;
}

void findBoundingBox(const char *fileName) {
	freopen(fileName, "r", stdin);
	int n; cin >> n;
	long long xMax, xMin, yMax, yMin;
	
	cin >> xMax >> yMax;
	xMin = xMax;
	yMin = yMax;
	for (int i = 1; i < n; i++) {
		long long x; cin >> x;
		long long y; cin >> y;
		
		if (x > xMax)
			xMax = x;
		else if (x < xMin)
			xMin = x;
			
		if (y > yMax)
			yMax = y;
		else if (y < yMin)
			yMin = y;
	}
	
	long long width = xMax - xMin;
	long long length = yMax - yMin;
	long long s = compareMax(width, length);
	cout << s * s;
}

int main() {
	
	findBoundingBox("DienTichDuongBao.inp");
	
	return 0;
}
