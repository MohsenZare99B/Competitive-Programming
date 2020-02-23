#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

const int N = 50;

int n, cnt = 0;
vector<int> diag1(N, 0), diag2(N, 0), column(N, 0);

void search(int y) {
    if(y == n) {
        cnt++;
        return;
    }else{
        for (int x = 0; x < n; x++) {
            if(column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
            column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
            search(y + 1);
            column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
        }
    }
}

signed main() {}