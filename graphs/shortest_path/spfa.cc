#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>

const int INF = 1e9;

vector<vector<pii> > g;
bool spfa(int s, vector<int> &d) {
	int n = g.size();
	d.assign(n, INF);
	vector<int> cnt(n, 0);
	vector<bool> inqueue(n, false);
	queue<int> q;

	d[s] = 0;
	q.push(s);
	inqueue[s] = true;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		inqueue[v] = false;

		for(auto edge : g[v]) {
			int to = edge.fi;
			int w = edge.se;

			if(d[v] + w < d[to]) {
				d[to] = w + d[v];
				if(!inqueue[to]) {
					q.push(to);
					inqueue[to] = true;
					cnt[to]++;
					if(cnt[to] > n) {
						return false; // negative cycle
					}
				} 
			}
		}
	}	
	return true;
}
signed main() {

}