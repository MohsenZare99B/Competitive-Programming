class FenMin{
public:
    int n;
    vector<int> bit;
    FenMin(vector<int> a) {
        n = sz(a);
        bit.assign(n + 5, INT64_MAX);
        for (int i = 0; i < n; i++) {
            update(i, a[i]);
        }
    }

    void update(int idx, int val) {
        for (idx++; idx <= n; idx += idx & -idx) {
            bit[idx] = min(bit[idx], val);
        }
    }

    int get_min(int idx) {
        int ret = INT64_MAX;
        for (idx++; idx > 0; idx -= idx & -idx) {
            ret = min(ret, bit[idx]);
        }
        return ret;
    }
};