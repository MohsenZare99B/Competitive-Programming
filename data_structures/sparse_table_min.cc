#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

const int N = 2e5, LG = 20;
int st[N][LG];

void build(vector<int> &a) {
    int n = sz(a);
    for (int j = 0; j < LG; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << j) - 1 < n) {
                st[i][j] = (j ? min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]) : a[i]);
            }
        }
    }
}

int query(int l, int r) {
    int dist_log = log2(r - l);
    return min(st[l][dist_log], st[r - (1 << dist_log) + 1][dist_log]);
}


signed main() {
    vector<int> v = {1, 3, 5};
    build(v);
    cout << query(0, 1) << "\n"; // 1

    v = {3, 5, 2, 5, 7, 8};
    build(v);
    cout << query(2, 4) << "\n"; // 2
}