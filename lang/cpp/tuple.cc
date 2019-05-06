#include <bits/stdc++.h>
using namespace std;
#define get(i, x) get<i>(x)
signed main()
{
    vector<tuple<int, int, int> > v;

    v.push_back({ 1, 3, 5 });
    v.push_back({ 0, 72, -2 });
    v.push_back({ -91, 0, 64 });

    sort(v.begin(), v.end());

    get(0, v[2]) = 999;

    for (auto& el : v) {
        cout << get<0>(el) << " " << get<1>(el) << " " << get<2>(el) << "\n";
        /*-91 0 64
		0 72 -2
		999 3 5*/
    }

    int a, b, c;
    tie(a, b, c) = v[0];
    cout << a << " " << b << " " << c << "\n";
    /*-91 0 64*/
}