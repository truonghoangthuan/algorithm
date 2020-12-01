#include <iostream>
using namespace std;

int nguyento(int n, int i = 2) {
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    
    if (n % i == 0)
        return 0;

    if (i * i > n)
        return 1;
    
    return nguyento(n, i + 1);
}

int main() {

    cout << nguyento(15);

    return 0;
}