#include <iostream>
using namespace std;

void countEvenOfString(string s) {
    int n = s.length();
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if ((int)s[j] % 2 == 0)
                cnt++;
        }
        a[i] = cnt;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main() {
    string s; cin >> s;

    countEvenOfString(s);

    return 0;
}