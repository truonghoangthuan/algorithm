#include<bits/stdc++.h> 

using namespace std;

struct Job 
{
	int profit;
    int deadLine;
};

struct DisjointSet
{
    int *parent; 
	
	DisjointSet(int n) 
    {
        parent = new int[n+1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    
    int find(int s)
    {
        if (s == parent[s])
            return s; 
        return parent[s] = find(parent[s]);
    }
    
    void merge(int u, int v)
    {
        parent[v] = u;
    } 
};

bool cmp(Job a, Job b) 
{
    return (a.profit > b.profit); 
}

int findMaxDeadline(struct Job arr[], int n) 
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i].deadLine);
    return ans; 
}

void printJobScheduling(Job arr[], int n) 
{
    sort(arr, arr + n, cmp);
	int maxDeadline = findMaxDeadline(arr, n); 
	DisjointSet ds(maxDeadline);
	int sum = 0;
    
	for (int i = 0; i < n; i++) 
    {
        int availableSlot = ds.find(arr[i].deadLine);
        if (availableSlot > 0) 
        {
            ds.merge(ds.find(availableSlot - 1), availableSlot);
            sum += arr[i].profit;
        }
    }
    cout << sum;
}

int main() 
{
    int n; cin >> n;
    Job arr[n];
    
    for (int i = 0; i < n; i++) {
    	cin >> arr[i].profit;
	}
	for (int i = 0; i < n; i++) {
    	cin >> arr[i].deadLine;
	}
    
    printJobScheduling(arr, n);

    return 0; 
}
