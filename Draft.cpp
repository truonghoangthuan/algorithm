#include <iostream>
using namespace std;

int binarySearch(int a[], int key, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] < key)
            end = mid - 1;
        else if (a[mid] > key)
            start = mid + 1;
        else
            return 1;
    }
    return 0;
}

int main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << binarySearch(a, 25, 0, n);

    return 0;
}