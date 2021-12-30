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

void bacLonNhat(Graph *G) {
	int max = 0;
	int pos = 0;
	for (int i = 1; i <= G->n; i++) {
		if (degree(G, i) > max) {
			max = degree(G, i);
			pos = i;
		}
	}
	cout << pos << " " << max;
}

int main() {
	Graph G;
	
	freopen("BacLonNhat.inp", "r", stdin);
	int n, m; cin >> n >> m;
	
	init_Graph(&G, n);
	addEdges(&G, m);
	
	bacLonNhat(&G);
	
	return 0;
}
