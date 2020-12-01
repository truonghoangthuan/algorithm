#include <iostream>
using namespace std;


int pow(int x, int n, int m){
    if(n == 0){
        return 1 % m;
    }

    else{
        int k = pow(x, n / 2, m);

        if(n % 2 == 0)
            return (k * k) % m;
        
        else
            return ((k * k) % m) * x % m;
    }
}


int main() {
    int x, n;

    cin >> x >> n;
    cout << pow(x, n, 10);

    return 0;
}