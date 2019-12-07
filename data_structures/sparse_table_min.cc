class SparseTable{
	public:
		vector<vector<int>> st;
		vector<int> lg;
		int N, LG;

		SparseTable(vector<int> &a) {
			N = sz(a) + 100, LG = 20;
			lg.assign(N, 0);
			st.assign(N, vector<int>(LG, INT64_MAX));
			precompute_lg();
			build(a);
		}

		void precompute_lg() {
			for (int i = 2; i < N; i++) {
				lg[i] = lg[i / 2] + 1;
			}
		}

		void build(vector<int> &a) {
			int n = sz(a);
			for (int i = 0; i < n; i++) {
				st[i][0] = a[i];
			}

			for (int j = 1; j < LG; j++) {
				for (int i = 0; i + (1 << (j - 1)) <= n; i++) {
					st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
				}
			}
		}

		int get_min(int l, int r) {
			int dist_log = lg[r - l];
			return min(st[l][dist_log], st[r - (1 << dist_log) + 1][dist_log]);
		}
};
