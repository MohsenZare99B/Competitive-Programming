#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>

const int INF = 1e9;

vector<vector<pii> > g;
void bfs_01(int s, vector<int> &d) {
	int n = g.size();
	d.assign(n, INF);
	d[s] = 0;
	deque<int> q;
	q.push_front(s);
	while(!q.empty()) {
		int v = q.front();
		q.pop_front();
		for(auto edge : g[v]) {
			int u = edge.fi;
			int w = edge.se;
			if(d[v] + w < d[u]) {
				d[u] = d[v] + w;
				if(w == 1) 
					q.push_back(u);
				else
					q.push_front(u);
			}
		}
	}

}
signed main() {

}