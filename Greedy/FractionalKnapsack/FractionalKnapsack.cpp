// C/C++ program to solve fractional Knapsack Problem 
#include <bits/stdc++.h> 

using namespace std; 

// Structure for an item which stores weight and corresponding 
// value of Item 
struct Item 
{ 
	int value, weight; 
}; 

// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 

// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
	// sorting Item on basis of ratio 
	sort(arr, arr + n, cmp); 

	// Uncomment to see new order of Items with their ratio 
	/* 
	for (int i = 0; i < n; i++) 
	{ 
		cout << arr[i].value << " " << arr[i].weight << " : " 
			<< ((double)arr[i].value / arr[i].weight) << endl; 
	} 
	*/

	int curWeight = 0; // Current weight in knapsack 
	double finalvalue = 0.0; // Result (value in Knapsack) 

	// Looping through all Items 
	for (int i = 0; i < n; i++) 
	{ 
		// If adding Item won't overflow, add it completely 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 

		// If we can't add current Item, add fractional part of it 
		else
		{ 
			int remain = W - curWeight; 
			finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
			break; 
		} 
	} 

	// Returning final value 
	return finalvalue; 
} 

// driver program to test above function 
int main() {
//	freopen("FractionalKnapsack.inp", "r", stdin); 
	int n, w; cin >> n >> w; // Weight of knapsack 
	Item arr[n];
	
	for (int i = 0; i < n; i++)
		cin >> arr[i].weight;
		
	for (int i = 0; i < n; i++)
		cin >> arr[i].value;
	
	printf("%.4lf", fractionalKnapsack(w, arr, n));
	return 0; 
} 

