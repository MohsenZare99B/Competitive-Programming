#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>

const int INF = 1e9;

vector<vector<pii> > g;
void dijkstra(int s, vector<int> &d, vector<int> &p) {
	int n = g.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> u(n, false);

	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}
		if (d[v] == INF)
			break;

		u[v] = true;
		for(auto edge : g[v]) {
			int to = edge.fi;
			int w = edge.se;

			if(d[v] + w < d[to]) {
				d[to] = d[v] + w;
				p[to] = v;
			}
		}
	}

}
signed main() {

}