#include<bits/stdc++.h>

using namespace std;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define int long long
#define sz(x) (int)(x.size())
#define f first
#define se second



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



const int N = 1e5;
int n;
int fen[N] = {0};

void fenwick_update(int p, int val) {
    for (int i = p; i <= n; i += (i & -i)) {
        fen[i] += val;
    }
}

int fenwick_sum(int p) {
    int res = 0;
    for (int i = p; i; i -= (i & -i)) {
        res += fen[i];
    }
    return res;
}



vector<int> a(N, INT64_MAX);
int sq_sz = ceil(sqrt(n));
vector<int> sqrt_dec(sq_sz, INT64_MAX);

void build_sqrt_decomposition() {
    for (int i = 0; i < sq_sz; i++) {
        int mn = INT64_MAX;
        for (int j = 0; j < sq_sz; j++) {
            sqrt_dec[i] = min(sqrt_dec[i], a[i * sq_sz + j]);
        }
    }
}

int query_sqrt_decomposition(int l, int r) {
    int res = INT64_MAX;
    for (int i = ceil(l / sq_sz); i < r / sq_sz; i++) {
        res = min(sqrt_dec[i], res);
    }
    for (int i = l; i < sq_sz * ceil(l / sq_sz); i++) {
        res = min(res, a[i]);
    }
    for (int i = max(sq_sz * (r / sq_sz), l); i <= r; i++) {
        res = min(res, a[i]);
    }
    return res;
}



const int LG = 20;
int st[N][LG];
vector<int> a(N, INT64_MAX);

void build_sparse_table() {
    for (int j = 0; j < LG; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << j) - 1 < n) {
                st[i][j] = (j ? min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]) : a[i]);
            }
        }
    }
}

int query_sparse_table(int l, int r) {
    int dist_log = log2(r - l);
    return min(st[l][dist_log], st[r - (1 << dist_log) + 1][dist_log]);
}



vector<int> s(4 * N, 0);

void build_segtree(int id = 1, int l = 0, int r = n) {
    if (r - l < 2) {
        s[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_segtree(id * 2, l, mid);
    build_segtree(id * 2 + 1, mid, r);
    s[id] = s[2 * id] + s[2 * id + 1];
}

void modify_segtree(int p, int x, int id = 1, int l = 0, int r = n) {
    s[id] += x - a[p];
    if (r - l < 2) {
        a[p] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (p < mid) {
        modify_segtree(p, x, id * 2, l, mid);
    } else {
        modify_segtree(p, x, id * 2 + 1, mid, r);
    }
}

int sum_segtree(int x, int y, int id = 1, int l = 0, int r = n) {
    if (r <= x or y <= l) {
        return 0;
    }
    if (x <= l && r <= y) {
        return s[id];
    }
    int mid = (r + l) / 2;
    return sum_segtree(x, y, 2 * id, l, mid) + sum_segtree(x, y, 2 * id + 1, mid, r);
}



vector<int> lazy(4 * N, 0);

void upd(int id, int l, int r, int x) {
    lazy[id] += x;
    s[id] += (r - l) * x;
}

void shift(int id, int l, int r) {
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, lazy[id]);
    upd(id * 2 + 1, l, mid, lazy[id]);
    lazy[id] = 0;
}

void increase(int x, int y, int v, int id = 1, int l = 0, int r = n) {
    if (r <= x or y <= l) {
        return;
    }
    if (x <= l && r <= y) {
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int mid = (l + r) / 2;
    increase(x, y, v, 2 * id, l, mid);
    increase(x, y, v, 2 * id + 1, mid, r);
    s[id] = s[2 * id] + s[2 * id + 1];
}

int sum_lazy(int x, int y, int id = 1, int l = 0, int r = n) {
    if (r <= x or y <= l) { return 0; }
    if (x <= l && r <= y) {
        return s[id];
    }
    shift(id, l, r);
    int mid = (l + r) / 2;
    return sum_lazy(x, y, 2 * id, l, mid) + sum_lazy(x, y, 2 * id + 1, mid, r);
}



int main() {
    ios::sync_with_stdio(false);
    ordered_set<int> os;
    os.insert(3);
    os.insert(1);
    cout << os.order_of_key(2) << "\n";
    cout << *os.find_by_order(0) << "\n";
}