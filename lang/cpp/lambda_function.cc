#include<bits/stdc++.h>
using namespace std;

signed main() {



    auto iterative_pow = [](int a, int b) {
        int res = 1;
        for(int i = 0; i < b; i++) {
            res *= a;
        }
        return res;
    };
    cout << iterative_pow(2, 5) << "\n"; // 32



    const int MOD = 1e9 + 7;
    auto pow_mod = [MOD](int a, int b, auto& pow_mod) {
        if(b == 0) {
            return 1;
        }
        int mid = pow_mod(a, b / 2, pow_mod);
        if(b % 2 == 1) {
            return (((mid * mid) % MOD) * a) % MOD;
        }else{
            return (mid * mid) % MOD;
        }
    };
    cout << pow_mod(2, 5, pow_mod) << "\n"; // 32



    vector<bool> visited(3, false);
    vector<vector<int>> g(3);
    g[0] = {1};
    g[1] = {0, 2};
    auto dfs = [&visited, &g](int v, auto& dfs) -> void {
        visited[v] = true;
        cout << v << " ";
        for(auto u : g[v]) {
            if(!visited[u]) {
                dfs(u, dfs);
            }
        }
    };
    dfs(0, dfs); // 0 1 2

}