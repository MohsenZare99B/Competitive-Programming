#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(x0) (ll)(x0.size())
#define PI 3.1415926536
#define f first
#define se second

const ll n=pow(10,7);
vector<bool> prime(n+10,true);
void prime_sieve(){
    prime[0]=prime[1]=0;
    for(ll p=2;p*p<=n;p++){
        if(prime[p]){
            for(ll i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
}
