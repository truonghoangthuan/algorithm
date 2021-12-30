#include <iostream>
#define NSIZE 10007
using namespace std;

struct Node {
	int vertex;
	struct Node* next;
};
typedef struct Node* AdjList[NSIZE + 1];

AdjList L;
int n, m;

int visited[NSIZE];

void init(AdjList *pL, int n) {
	for(int i = 0; i < n; i++) {
		(*pL)[i] = new Node;
		(*pL)[i]->next = NULL;
	}
}

void insertNode(AdjList L, int i, int j) {
	struct Node *p = new Node;
	
	if(p == NULL) {
		return;
	}
	p->vertex = j;
	p->next = L[i]->next;
	L[i]->next = p;
}

/*int isAdjacent(int u, int v, AdjList L) {
	struct Node *p = L[u];
	while(p->next != NULL) {
		if(p->next->vertex == v)
			return 1;
		p = p->next;	
	}
}*/

void buildGraph(AdjList *pL, int *pN, int *pM) {
	int i, x, y;
	
	scanf("%d%d", pN, pM);
	init(pL, *pN);
	for(i = 1; i <= (*pM); i++) {
		cin >> x >> y;
		insertNode((*pL), x, y);
		insertNode((*pL), y, x);
	}
}

void printGraph(AdjList L, int N, int M) {
	int i, j;
	int x, y;
	
	for(i = 1; i <= N; i++) {
		struct Node *p = L[i];
		cout << "Node " << i << endl;
		while(p->next != NULL) {
			cout << p->next->vertex;
			p = p->next;
		}
	}
}

void doDFS(int start) {
	struct Node *p;
	
	visited[start] = 1;
	p = L[start];
	while(p->next != NULL) {
		int u = p->next->vertex;
		if(!visited[u]) {
			doDFS(u);
		}
		p = p->next;
	}
}

void solve() {
	int start, i, cnt;
	
	freopen("Input\\GraphInput\\Cau\\cau01.inp", "r", stdin);
	init(&L, n);
	buildGraph(&L, &n, &m);
	for(i = 0; i < NSIZE; i++)
		visited[i] = 0;
	cin >> start;
	doDFS(start);
	cnt = 0;
	for(i = 0; i < NSIZE; i++)
		if(visited[i])
			cnt++;
	cout << (n - cnt);
}

int main() {
	
	solve();
	
	return 0;
}
