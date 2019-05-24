#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n;
vector<vector<int> > ans;

vector<int> subset;
void search(int k) {
    if (k == n) {
        ans.push_back(subset);
    }else {
        search(k + 1);
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
    }
}

void bitmask_search() {
    for (int b = 0; b < (1 << n); b++) {
        vector<int> subset;
        for(int i = 0; i < n; i++) {
            if (b & (1 << i)) subset.push_back(i);
        }
        ans.push_back(subset);
    }
}

signed main() {

}