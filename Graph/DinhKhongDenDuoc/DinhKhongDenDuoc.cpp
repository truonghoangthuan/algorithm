#include <iostream>
#define Max_Vertices 508
#define Max_Length 508
#define Max_Element 508
using namespace std;

//Cau truc kieu Graph
typedef struct {
	int A[Max_Vertices][Max_Vertices];
	int n;
} Graph;

//Nhap do thi
void init_Graph(Graph *G, int n) {
	G->n = n;
	for (int i = 1; i <= G->n; i++)
		for (int j = 1; j <= G->n; j++)
			G->A[i][j] = 0;
}

//In do thi dang matrix
void print_Graph(Graph G, int n) {
	for (int i = 1; i <= G.n; i++) {
		for (int j = 1; j <= G.n; j++)
			cout << G.A[i][j] << " ";
		cout << "\n";
	}
}

//Chen mot canh
void addOneEdge(Graph *G, int x, int y) {
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

void addEdges(Graph *G, int n) {
	int u, v;
	for (int i = 1; i <= n; i++) {
		cin >> u >> v;
		addOneEdge(G, u, v);
	}
}

//Kiem tra lang gieng
int isAdjacent(Graph *G, int x, int y) {
	return (G->A[x][y] != 0);
}

//Tinh bac
int degree(Graph *G, int x) {
	int deg = 0;
	for (int i = 1; i <= G->n; i++)
		if (G->A[i][x] == 1)
			deg++;
	return deg;
}

//==========================================//

//Cau truc List
typedef struct {
	int data[Max_Length];
	int size;
} List;

//Tao List rong
void makenullList (List *L) {
	L->size = 0;
}

//Them phan tu vao cuoi List
void insertList(List *L, int x) {
	L->data[L->size] = x;
	L->size++;
}

//Lay phan tu tai vi tri i cua List
int getElement(List *L, int n) {
	return L->data[n - 1];
}

//Tim ten lang gieng cua dinh x
List findNeighbors(Graph *G, int x) {
	List L;
	makenullList(&L);
	
	for (int i = 1; i <= G->n; i++)
		if (G->A[i][x] == 1)
			insertList(&L, i);
	
	return L;
}

//In lang gieng cua tung nut
void printNeighbors(Graph *G) {
	for (int i = 1; i <= G->n; i++) {
		List L = findNeighbors(G, i);
		cout << "Neighbors of " << i << ": ";
		for (int j = 1; j <= L.size; j++)
			cout << getElement(&L, j) << " ";
		cout << endl;
	}
}

//================================//
//Cau truc Stack
typedef struct {
	int data[Max_Element];
	int size;
} Stack;

//Tao Stack rong
void makenullStack(Stack *S) {
	S->size = 0;
}

//Them 1 phan tu vao Stack
void insertStack(Stack *S, int x) {
	S->data[S->size] = x;
	S->size++;
}

//Lay phan tu cua Stack
int top(Stack *S) {
	return S->data[S->size - 1];
}

//Xoa 1 phan tu Stack
void pop(Stack *S) {
	S->size--;
}

//Kiem tra Stack rong
int isEmptyStack(Stack *S) {
	return (S->size == 0);
}

//DFS algorithms
List depthFirstSearch(Graph *G, int x) {
	Stack S;
	makenullStack(&S);
	insertStack(&S, x);
	
	//Danh dau dinh chua duyet
	int visited[Max_Vertices];
	for(int i = 1; i <= G->n; i++)
		visited[i] = 0;
	
	List lastList;
	makenullList(&lastList);
	while (!isEmptyStack(&S)) {
		int u = top(&S);
		pop(&S);
		if (visited[u] == 1)
			continue;
		insertList(&lastList, u);
		visited[u] = 1;
		//Tham cac dinh ke cua u
		List L = findNeighbors(G, u);
		for (int i = 1; i <= L.size; i++) {
			int v = getElement(&L, i);
			if (visited[v] == 0)
				insertStack(&S, v);
		}
	}
	
	return lastList;
}

//Duyet tat ca phan tu bang DFS
void dfsForAll(Graph *G) {
	int mark_dfs[Max_Vertices];
	for (int i = 1; i <= G->n; i++)
		mark_dfs[i] = 0;
	for (int i = 1; i <= G->n; i++) {
		if (mark_dfs[i] == 0) {
			List dfs = depthFirstSearch(G, 1);
			for (int j = 1; j <= dfs.size; j ++) {
				int k = getElement(&dfs, j);
				cout << "Checked node " << k << endl;
				mark_dfs[k] = 1;
			}
		}
	}	
}

//Tim so dinh khong den duoc tu dinh x
void tinhSoDinhKhongDenDuoc(Graph *G, int x) {
	List dfs = depthFirstSearch(G, x);
	int cnt = 0;
	for (int i = 1; i <= dfs.size; i++) {
		cnt++;
	}
	cout << G->n - cnt << endl;
}

int main() {
	Graph G;
	
	//freopen("DinhKhongDenDuoc.inp", "r", stdin);
	int n, m; cin >> n >> m;
	
	init_Graph(&G, n);
	addEdges(&G, m);
	
	int x; cin >> x;
	tinhSoDinhKhongDenDuoc(&G, x);
	
	return 0;
}
