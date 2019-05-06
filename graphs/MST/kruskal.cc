#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> par(N, -1);

int root(int v) { return par[v] < 0 ? v : (par[v] = root(par[v])); }

void merge(int a, int b) {
    if ((a = root(a)) == (b = root(b)))
        return;
    if (par[b] < par[a])
        swap(a, b);
    par[a] += par[b];
    par[b] = a;
}

struct Edge{
	int u, v, weight;
	bool operator<(Edge & other) {
		return weight < other.weight;
	}
};

int n;
vector<Edge> edges, result;
int cost = 0; 

void kruskal() {
	sort(edges.begin(), edges.end());

	for(Edge e : edges) {
		if(root(e.u) != root(e.v)) {
			cost += e.weight;
			result.push_back(e);
			merge(e.u, e.v);
		}
	}
}

signed main() {

}