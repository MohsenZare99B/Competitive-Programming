#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

const int N = 30;
int n;

vector<vector<int> > ans;
vector<bool> chosen(N, false);
vector<int> permuation;

void search() {
    if (sz(permuation) == n) {
        ans.push_back(permuation);
    }else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permuation.push_back(i);
            search();
            chosen[i] = false;
            permuation.pop_back();
        }
    }
}

void stl_permutation() {
    permuation.clear();
    for (int i = 0; i < n; i++) {
        permuation.push_back(i);
    }

    do {
        ans.push_back(permuation);
    }while(next_permutation(permuation.begin(), permuation.end()));

}

signed main() {}