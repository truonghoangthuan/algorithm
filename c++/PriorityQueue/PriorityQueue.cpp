#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxSize 100

#define MINVALUE -32768 
typedef int KeyType;
typedef struct {
    KeyType Keys[MaxSize];
    int size;
} PriorityQueue;

PriorityQueue getQueue() {
    PriorityQueue Q;
    Q.size = 0;
    return Q;
}

bool isEmpty(PriorityQueue* Q) {
    return Q->size == 0;
}

bool isFull(PriorityQueue* Q) {
    return Q->size == MaxSize;
}

void swap2Num(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

KeyType parent(int i) {
    return (i - 1) / 2;
}

void increaseKey(PriorityQueue* Q, int i, KeyType k) {
    if (k < Q->Keys[i])
        return;
    Q->Keys[i] = k;
    while (i > 0 && Q->Keys[parent(i)] < Q->Keys[i]) {
        swap2Num(&Q->Keys[i], &Q->Keys[parent(i)]);
        i = parent(i);
    }
}

void insert(PriorityQueue* Q, KeyType k) {
    Q->Keys[Q->size] = MINVALUE;
    int i = Q->size;
    increaseKey(Q, i, k);
    Q->size++;
}

int max(PriorityQueue* Q) {
    return Q->Keys[0];
}

void maxHeapify(PriorityQueue* Q, int i) {
    int largest = 0;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= Q->size && Q->Keys[left] > Q->Keys[i])
        largest = left;
    else
        largest = i;
    if (right <= Q->size && Q->Keys[right] > Q->Keys[largest])
        largest = right;
    if (largest != i) {
        swap2Num(&Q->Keys[i], &Q->Keys[largest]);
        maxHeapify(Q, largest);
    }
}

void buildMaxHeap(PriorityQueue* Q) {
    for (int i = Q->size / 2; i >= 0; i--)
        maxHeapify(Q, i);
}

int extractMax(PriorityQueue* Q) {
    if (MaxSize == 0)
        return -1;
    
    int max = Q->Keys[0];
    Q->size--;
    Q->Keys[0] = Q->Keys[Q->size];
    maxHeapify(Q, 0);

    return max;
}

int main() {

    int i;
    PriorityQueue Q = { {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}, 10 };
    buildMaxHeap(&Q);
    for (i = 0; i <= Q.size - 1; i++)
        printf("%d ", Q.Keys[i]);
}
