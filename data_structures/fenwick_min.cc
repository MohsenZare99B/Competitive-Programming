#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int) (x.size())

struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(sz(a)) {
        for (int i = 0; i < sz(a); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF; // -INF => FenwickTreeMax
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]); // max(ret, bit[r]) => FenwickTreeMax
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val); // max(bit[idx], val) => FenwickTreeMax
    }
};

signed main() {
    vector<int> a = {3, 5, 2, 5, 7, 8};
    FenwickTreeMin f(a);
    cout << f.getmin(0) << "\n"; // 3
    cout << f.getmin(2) << "\n"; // 2

    f.update(1, -10);
    cout << f.getmin(2) << "\n"; // -10
}