class Fenwick{
public:
    int n;
    vector<int> bit;
    Fenwick(vector<int> a) {
        this->n = sz(a);
        bit.assign(n + 5, 0);
        for (int i = 0; i < n; i++) {
            add(i, a[i]);
        }
    }

    void add(int idx,int val) {
        for (idx++; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int sum(int idx) {
        int ret = 0;
        for (idx++; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};