#include<bits/stdc++.h>
using namespace std;


signed main()
{
    random_device dev;
    mt19937 rng(dev());
    for(int i = 0; i < 100; i++) {
        uniform_int_distribution<mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
        cout << dist6(rng) << endl;
    }
}