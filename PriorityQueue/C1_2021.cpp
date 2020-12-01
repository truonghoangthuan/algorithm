#include <stdio.h>

#define MaxSize 100

#define MINVALUE -32768 
typedef long long KeyType;
typedef struct {
    KeyType Keys[MaxSize];
    long long size;
}PriorityQueue;

void makeNullQueue(PriorityQueue *Q) {
	Q->size = 0;
}

void swap2Num(long long *x, long long *y) {
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

KeyType parent(long long &i) {
    return i / 2;
}

void increaseKey(PriorityQueue* Q, long long i, KeyType k) {
    if (k < Q->Keys[i])
        return;
    while ((i > 1) && (Q->Keys[parent(i)] > Q->Keys[i])) {
        swap2Num(&Q->Keys[i], &Q->Keys[parent(i)]);
        i = parent(i);
    }
}

void insert(PriorityQueue* Q, KeyType k) {
    Q->size = Q->size + 1;
    Q->Keys[Q->size] = k;
    long long i = Q->size;
    increaseKey(Q, i, k);
}

long long max(PriorityQueue* Q) {
    return Q->Keys[0];
}

void maxHeapify(PriorityQueue* Q, long long i) {
    long long largest = 0;
    long long left = 2 * i;
    long long right = 2 * i + 1;
    if ((left <= Q->size) && (Q->Keys[left] < Q->Keys[i]))
        largest = left;
    else
    	largest = i;
    if ((right <= Q->size) && (Q->Keys[right] > Q->Keys[largest]))
        largest = right;
    if (largest != i)
    {
        swap2Num(&Q->Keys[i], &Q->Keys[largest]);
        maxHeapify(Q, largest);
    }
}

void buildMaxHeap(PriorityQueue* Q) {
    for (long long i = Q->size / 2; i >= 0; i--)
        maxHeapify(Q, i);
}

long long extractMax(PriorityQueue* Q) {
    if (MaxSize == 0)
    {
        return -1;
    }
    long long max = Q->Keys[0];
    Q->Keys[0] = Q->Keys[Q->size];
    Q->size--;
    maxHeapify(Q, 0);

    return max;
}

int main() {
    PriorityQueue Q;
    makeNullQueue(&Q);
    
    long long m, n; scanf("%lld%lld", &m, &n);
    for (long long i = 0; i < m; i++) {
    	long long x; scanf("%lld", &x);
    	insert(&Q, x);
	}
	buildMaxHeap(&Q);
	
	for (int i = 0; i < m; i++) 
		printf("%d ", Q.Keys[i]);
	printf("\n");
    
    long long s = 0;
    long long a = 0;
	for (long long i = 0; i < n; i++) {
		a = extractMax(&Q);
		s += a;
		insert(&Q, a - 1);
		buildMaxHeap(&Q);
	}
	printf("%lld", s);
}
