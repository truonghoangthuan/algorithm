#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct {
    int value;
    int weight;
} item;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 
  
// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack01(int W, item items[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (items[i - 1].weight <= w) 
                K[i][w] = max( 
                    items[i - 1].value + K[i - 1][w - items[i - 1].weight], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
}

int main() {
    freopen("ShoppingAtMega.inp", "r", stdin);
    int t; cin >> t;
    int i, j, k;
    for (i = 0; i < t; i++) {
        int n; cin >> n;
        item items[n];

        for (j = 0; j < n; j++)
            cin >> items[j].value >> items[j].weight;

        int G; cin >> G;
        int sum = 0;
        for (k = 0; k < G; k++) {
            int perWeight; cin >> perWeight;
            sum += knapSack01(perWeight, items, n);
        }
        cout << sum << endl;
    }

    return 0;
}