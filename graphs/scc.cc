#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define sz(x) (int)(x.size())
const int N = 1e5;

vector<vector<int> > g, gr;
vector<bool> visited(N, false);
vector<vector<int> > comps;
vector<int> order;
int n, m;

void topo(int v) {
    visited[v] = true;
    for(auto &u : g[v]) {
        if(!visited[u]) {
            topo(u);
        }
    }
    order.push_back(v);
}

void dfs(int v) {
    visited[v] = true;
    comps.back().push_back(v);
    for(auto &u : gr[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

void read_input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
}

signed main() {
    read_input();
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            topo(i);
    }

    visited.assign(N, false);

    reverse(order.begin(), order.end());
    for(auto &v : order) {
        if(!visited[v]) {
            comps.push_back({});
            dfs(v);
        }
    }
}