#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Disjoint sets
int fathers[100000];

int find(int x) {
	if (fathers[x] == x)
		return x;
	return find(fathers[x]);
}

void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	fathers[fx] = fy;
}


//kruskal algorithm
void findCost(const char *fileName) {
	freopen(fileName, "r", stdin);
	int n, m;
	int a, b, w;
	vector <pair <int, pair<int, int>>> edges;
	
	cin >> n >> m;
	//initialize fathers
	for (int i = 0; i < n; i++)
		fathers[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edges.push_back(make_pair(w, make_pair(a, b)));
	}
	
	int mst_w = 0, mst_e = 0, mst_ni = 0;
	//sort edges
	sort(edges.begin(), edges.end());
	while((mst_e < n-1) || (mst_ni < m)) {
		a = edges[mst_ni].second.first;
		b = edges[mst_ni].second.second;
		w = edges[mst_ni].first;
		
		if (find(a) != find(b)) {
			//unite edges
			merge(a, b);
			//add weight
			mst_w += w;
			//add edge
			mst_e++;
		}
		//increase index
		mst_ni++;
	}
	cout << mst_w << endl;
}

int main() {
	
	findCost("kruskal02.inp");
	
	return 0;
}
