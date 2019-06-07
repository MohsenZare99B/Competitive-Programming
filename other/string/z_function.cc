#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

vector<int> z_function(string s) {
    int n = sz(s);
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
}