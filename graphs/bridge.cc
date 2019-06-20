#include<bits/stdc++.h>
#define int long long
#define sz(x) (int) (x.size())
using namespace std;

const int N = 1e5;

vector<vector<int>> g;
vector<bool> visited(N, false);
vector<int> tin(N, -1), low(N, -1);
vector<pair<int, int>> ans;

int timer = 0;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v])
                ans.push_back({v, to});
        }
    }
}


signed main() {
}