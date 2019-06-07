#include<bits/stdc++.h>
using namespace std;
#define int long long
const double pi = 2 * acos(0);

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    cout << setprecision(3) << fixed;
    for(int tc = 1; tc <= T; tc++) {
        int d, l;
        cin >> d >> l;
        double ans =  pi * (l * sqrt(l * l - d * d)) / 4.0;
        cout << ans << "\n";
    }
}