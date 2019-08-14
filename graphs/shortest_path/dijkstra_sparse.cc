const int INF = 1e9;

vector<vector<pii> > g;
void dijkstra(int s, vector<int>& d, vector<int>& p)
{
    int n = g.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({ 0, s });
    while (!pq.empty()) {
        int v = pq.top().se;
        int d_v = pq.top().fi;
        pq.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : g[v]) {
            int u = edge.fi;
            int w = edge.se;

            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                p[u] = v;
                pq.push({ d[u], u });
            }
        }
    }
}
