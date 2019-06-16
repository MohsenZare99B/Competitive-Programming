#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>

const int INF = 1e9;

struct Edge {
    int w = INF, to = -1;
};

vector<vector<int> > g;
int n, total_weight = 0;
vector<bool> selected(n, false);
vector<Edge> min_e(n);
vector<pii> res;

bool prim()
{
    min_e[0].w = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
                v = j;
            }
        }

        if (min_e[v].w == INF) {
            return false;
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            res.push_back({ v, min_e[v].to });

        for (int to = 0; to < n; to++) {
            if (g[v][to] < min_e[to].w)
                min_e[to] = { g[v][to], v };
        }
    }
    return true;
}

signed main()
{
}