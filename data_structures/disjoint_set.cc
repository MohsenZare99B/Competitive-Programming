#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> par(N, -1);

int root(int v) { return par[v] < 0 ? v : (par[v] = root(par[v])); }

void merge(int a, int b)
{
    if ((a = root(a)) == (b = root(b)))
        return;
    if (par[b] < par[a])
        swap(a, b);
    par[a] += par[b];
    par[b] = a;
}

signed main()
{
}