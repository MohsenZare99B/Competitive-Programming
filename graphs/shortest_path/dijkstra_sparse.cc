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
	p.assign(n, INF);

	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0, s});
	while(!pq.empty()) {
		int v = pq.top().se;
		int d_v = pq.top().fi;
		pq.pop();
		if(d_v != d[v])
			continue;

		for(auto edge : g[v]) {
			int to = edge.fi;
			int w = edge.se;
			
			if(d[v] + w < d[to]) {
				d[to] = d[v] + w;
				p[to] = v;
				pq.push({d[to], to});
			}
		}
	}

}
signed main() {

}