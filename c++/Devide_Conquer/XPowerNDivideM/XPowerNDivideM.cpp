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
    int x, n, m;

    cin >> x >> n >> m;
    cout << pow(x, n, m);

    return 0;
}