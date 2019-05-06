#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector<vector<int> > g;
vector<bool> visited(N, false);
vector<int> res;

void topo(int v) {
	visited[v] = true;
	for(auto u : g[v]) {
		if(!visited[u])
			topo(u);
	}
	res.push_back(v);
}

signed main() {
	reverse(res.begin(), res.end());
}