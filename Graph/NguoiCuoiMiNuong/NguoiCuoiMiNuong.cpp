#include <iostream>
using namespace std;

#define MaxSize 10007

//=============Queue==============//
typedef struct{
    int Node[MaxSize];
    int Front, Rear;
} Queue;

void makeNullQueue(Queue *Q){
    Q->Front = Q->Rear = 0;
}

bool isEmpty(Queue Q){
    return Q.Front == Q.Rear;
}

bool isFull(Queue Q){
    return (Q.Rear + 1) % MaxSize == Q.Front;
}

void insertQueue(int x, Queue *Q){
    if (!isFull(*Q)) {
        Q->Node[Q->Rear] = x;
        Q->Rear = (Q->Rear + 1) % MaxSize;
    }
}

void pop(int *pTop, Queue *Q){
    if (!isEmpty(*Q)) {
        *pTop = Q->Node[Q->Front];
        Q->Front = (Q->Front + 1) % MaxSize;
    }
}
//================================//

//=========QuickSort=========//
void swap(int& x, int& y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int findPivot(int a[], int i, int j) {
	int firstkey = a[i];
	int k = i + 1;

	while (k <= j && a[k] == firstkey)	k++;
	if (k > j)	return -1;
	if (a[k] > firstkey)	return k;
	return i;
}

int partrition(int a[], int i, int j, int pivot) {
	int L = i, R = j;

	while (L <= R)
	{
		while (a[L] < pivot)	L++;
		while (a[R] >= pivot)	R--;
		if (L < R)	swap(a[L], a[R]);
	}
	return L;
}

void quickSort(int a[], int i, int j) {
	int pivot, k;
	int pivotIndex = findPivot(a, i, j);
	if (pivotIndex != -1)
	{
		pivot = a[pivotIndex];
		k = partrition(a, i, j, pivot);
		quickSort(a, i, k - 1);
		quickSort(a, k, j);
	}
}
//================================//

//=============Graph==============//
struct Node {
    int vertex;
    int weight;
    Node* Next;
};

typedef struct Node* AdjList[MaxSize + 1];

AdjList L;
Queue Q;
int num_of_vertex, num_of_edge;

void init(AdjList* L, int size){
    for (int i = 0; i <= size; i++) {
        (*L)[i] = (Node*) malloc(sizeof(Node));
        (*L)[i]->Next = NULL;
    }
}

void insertNode(AdjList L, int i, int j, int weight){
    Node* p = (Node*) malloc(sizeof(Node));
    if (p == NULL) {
        return;
    }
    p->weight = weight;
    p->vertex = j;
    p->Next = L[i]->Next;
    L[i]->Next = p;
}

void buildGraph(AdjList *L, int *num_of_vertex){
    int first_vertex, second_vertex;
    cin >> *num_of_vertex;
    init(L, *num_of_vertex);
    for(int i = 1; i <= *num_of_vertex - 1; i++){
        cin >> first_vertex >> second_vertex;
        int w = 1;
        insertNode(*L, first_vertex, second_vertex, w);
        insertNode(*L, second_vertex, first_vertex, w);
    }
}

void releaseList(Node* L1){
    Node* q;
    Node* p = L1;
    while (p->Next != NULL) {
        q = p->Next;
        p->Next = q->Next;
        free(q);
    }
}

void releaseGraph(AdjList *L, int num_of_vertex, int num_of_edge){
    for (int i = 0; i <= num_of_vertex; i++) {
        releaseList((*L)[i]);
    }
}

void printGraph(AdjList L, int num_of_vertex){
    for (int i = 1; i <= num_of_vertex; i++) {
        Node* p = L[i];
        cout << i << " " << endl;
        while (p->Next != NULL) {
            cout << p->Next->vertex << " " << endl;
            p = p->Next;
        }
    }
}

int getDistance(int start, int end){
    Node* p;
    int u, v;
    int distance[MaxSize];
    bool visit[MaxSize];
    for (int i = 1; i <= MaxSize; i++) {
        distance[i] = 0;
        visit[i] = false;
    }
    
    makeNullQueue(&Q);
    insertQueue(start, &Q);
    distance[start] = 0;
    visit[start] = true;
    
    while (!isEmpty(Q)) {
        pop(&u, &Q);
        if (u == end) {
            return distance[u];
        }
        
        p = L[u];
        while (p->Next != NULL) {
            v = p->Next->vertex;
            if (!visit[v]) {
                distance[v] = distance[u] + 1;
                insertQueue(v, &Q);
                visit[v] = true;
            }
            p = p->Next;
        }
    }
    return distance[u];
}
//============================//

void miNuong(/*const char* inputFile*/) {
//    freopen(inputFile, "r", stdin);
    int num_of_vertex;
    
    buildGraph(&L, &num_of_vertex);
//    printGraph(L, num_of_vertex);
    
    int khoangCachNuoc[num_of_vertex];
	for (int i = 2; i <= num_of_vertex; i++) {
		khoangCachNuoc[i] = getDistance(1, i);
		//cout << khoangCachNuoc[i] << endl;
	}
		
    int min = 10007;
    int pos;
    int nuocHoiCuoi; cin >> nuocHoiCuoi;
    for (int j = 1; j <= nuocHoiCuoi; j++) {
        int tenNuoc; cin >> tenNuoc;
        if (khoangCachNuoc[tenNuoc - 1] < min) {
        	min = khoangCachNuoc[tenNuoc];
        	pos = tenNuoc;
		}
    }
    
	cout << pos;
}

int main() {
	
	miNuong(/*"NguoiCuoiMiNuong.inp"*/);
	
	return 0;
}
