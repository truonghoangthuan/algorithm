#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (a == 0)
        return b;

    if (b == 0)
        return a;
        
    return GCD(b, a % b);
}

int main() {

    cout << GCD(1, -5);

    return 0;
}