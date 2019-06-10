#include<bits/stdc++.h>
using namespace std;
// #define int long long

const int N = 1e6;
int succ[N];


int length, first;
void floyd(int x) { 
    int a = succ[x];
    int b = succ[succ[x]];
    while (a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }


    a = x;
    while (a != b) {
        a = succ[a];
        b = succ[b];
    }
    first = a; // the first node that belongs to the cycle 


    b = succ[a];
    length = 1; // length of cycle
    while (a != b) {
        b = succ[b];
        length++;
    }

}

signed main() {
    succ[0] = 1;
    succ[1] = 2;
    succ[2] = 3;
    succ[3] = 4;
    succ[4] = 2;

    // (0) -> (1) -> (2) -> (3) -> (4) ---\
    //                ^                   |
    //                |-------------------/


    floyd(0);
    cout << first << "  " << length << "\n"; // 2  3

    floyd(1);
    cout << first << "  " << length << "\n";// 2  3

    floyd(2);
    cout << first << "  " << length << "\n";// 2  3

    floyd(3);
    cout << first << "  " << length << "\n"; // 3  3

    floyd(4);
    cout << first << "  " << length << "\n";// 4  3
}