#include <iostream> 
using namespace std;

int main() { 
   int num = 63972, rev = 0;

   while(num > 0) { 
      rev = rev * 10 + num % 10; 
      num = num / 10; 
   }
   cout << rev;

   return 0; 
}

// #include <iostream>
// using namespace std;

// int modulo_reverse(long a, long p){
// 	for (long long i = 0; i < p; i++)
// 		if(((long long)a * i) % p == 1)
// 			return i;

// 	return -1;
// }
// int main(){
// 	int a, p; cin >> a >> p;
	
//    cout << modulo_reverse(a,p);
// }