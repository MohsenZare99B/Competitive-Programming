#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(sz(a)) {
        for (int i = 0; i < sz(a); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


signed main() {
    vector<int> a = {1, 2, 3, 4};
    FenwickTree f(a);
    cout << f.sum(0, 1) << "\n"; // 3
    f.add(1, 5);
    cout << f.sum(1, 1) << "\n"; // 7
    cout << f.sum(1) << "\n"; // 8
}