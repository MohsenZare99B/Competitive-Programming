#include<bits/stdc++.h>
using namespace std;
#define int long long

bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) return false;
    }
    return true;
}

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f.push_back(x); 
            n /= x;
        }
    }
    if(n > 1) f.push_back(n);
    return f;
}

vector<int> eratosthenes(int n) {
    vector<int> sieve(n, 0);
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue;
        for(int u = x * 2; u <= n; u += x) {
            sieve[u] = x;
        }
    }
    return sieve;
}


