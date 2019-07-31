class Fen2D {
public:
    int n, m;
    vector<vector<int>> bit;
    Fen2D(vector<vector<int>> a) {
        this->n = sz(a);
        this->m = sz(a[0]);
        bit.assign(n + 5, vector<int>(m + 5, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i, j, a[i][j]);
            }
        }
    }

    void add(int x, int y, int val) {
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
};