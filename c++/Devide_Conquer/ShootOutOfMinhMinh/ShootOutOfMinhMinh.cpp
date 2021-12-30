#include <iostream>
using namespace std;

// Minh Minh
void shootOut(const char* fileName) {
	int n, A[100000], B[100000], i, j, q;
	freopen(fileName, "r", stdin);

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cin >> q;
	for (i = 0; i < q; i++)
	{
		cin >> B[i];
	}

	for (i = 0; i < q; i++)
	{
		int soLuong = 0, sucManh = 0;
		for (j = 0; j < n; j++)
		{
			if (B[i] >= A[j])
			{
				soLuong++;
				sucManh += A[j];
			}
		}
		cout << soLuong << " " << sucManh << endl;
	}
}

int main() {

    shootOut("ShootOutOfMinhMinh.inp");

    return 0;
}