#include <stdio.h>
#include <malloc.h>

#define MaxSize 100000000007

#define MINVALUE -32768 

//======PriorityQueue======//
typedef long long KeyType;
typedef struct {
    KeyType *Keys;
    long long size;
}PriorityQueue;

void makenullQueue(PriorityQueue* Q) {
    Q->size = 0;
}

bool isEmpty(PriorityQueue Q) {
    return Q.size == 0;
}

bool isFull(PriorityQueue* Q) {
    return Q->size == MaxSize;
}

void swap2Num(KeyType* x, KeyType* y) {
    KeyType tmp = *x;
    *x = *y;
    *y = tmp;
}

KeyType parent(long long i) {
    return i / 2;
}

void decreaseKey(PriorityQueue* Q, long long i, KeyType k) {
    if (k > Q->Keys[i])
        return;
    Q->Keys[i] = k;
    while (i > 0 && Q->Keys[parent(i)] > Q->Keys[i]) {
        swap2Num(&Q->Keys[i], &Q->Keys[parent(i)]);
        i = parent(i);
    }
}

void insert(PriorityQueue* Q, KeyType k) {
    Q->size++;
    Q->Keys[Q->size - 1] = MaxSize;
    long long i = Q->size - 1;
    decreaseKey(Q, i, k);
}
//============================//

//=======Heapsort=======//
void minHeapify(PriorityQueue* Q, long long i)
{
    long long smallest = 0;
    long long left = 2 * i;
    long long right = 2 * i + 1;
    
    if (left < Q->size && Q->Keys[left] < Q->Keys[i])
        smallest = left;
    else
        smallest = i;
    
    if (right < Q->size && Q->Keys[right] < Q->Keys[smallest])
        smallest = right;
    
    if (smallest != i)
    {
        swap2Num(&Q->Keys[i], &Q->Keys[smallest]);
        minHeapify(Q, smallest);
    }
}

void buildMinHeap(PriorityQueue* Q) {
    for (long long i = Q->size / 2 - 1; i >= 0; i--)
        minHeapify(Q, i);
}

long long extractMin(PriorityQueue* Q)
{
    long long min = Q->Keys[0];
    swap2Num(&Q->Keys[0], &Q->Keys[Q->size - 1]);
    Q->size--;
    minHeapify(Q, 0);

    return min;
}
//=========================//

void mergeCount(PriorityQueue* Q) {
    long long k1, k2;
    long long cnt = 0;

    while (1) {
        k1 = extractMin(Q);
        k2 = extractMin(Q);
        cnt += (k1 + k2);
        
        if (isEmpty(*Q))
            break;
            
        insert(Q, k1 + k2);
    }
    printf("%lld", cnt);
}

int main() {
    long long i;
    PriorityQueue Q;

    makenullQueue(&Q);
    scanf("%lld", &Q.size);
    Q.Keys = (KeyType*)malloc(Q.size*sizeof(KeyType));
    for (i = 0; i <= Q.size-1; i++)
        scanf("%lld", &Q.Keys[i]);
    buildMinHeap(&Q);

    mergeCount(&Q);
    
    free(Q.Keys);

    return 0;
}
