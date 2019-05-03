#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std; 

signed main() {
	int n = 8;
	int a[] = {1, 1, 2, 2, 2, 2, 4, 4};
	int x = 2;

	int k = 0;
	for(int b = n / 2; b >= 1; b /= 2) {
		while(k + b < n && a[k + b] <= x) k += b;
	}

	if(a[k] == x) {
		cout << "index : " << k << "\n"; // index: 5
	}

	x = 342;
	k = 0;
	for(int b = n / 2; b >= 1; b /= 2) {
		while(k + b < n && a[k + b] <= x) k += b;
	}
	if(a[k] == x) {
		cout << "index : " << k << "\n"; // index: 7
	}

	x = 3;
	k = 0;
	for(int b = n / 2; b >= 1; b /= 2) {
		while(k + b < n && a[k + b] <= x) k += b;
	}
	if(a[k] != x) {
		cout << "index : " << k << "\n"; // index: 5
	}
	//dar vaghe k bozorgtarin indexi ke a[k] <= x hast ro mide

	auto eq = equal_range(a, a + n, 2);
	cout << eq.fi - a<< " " << eq.se - a << " " << eq.se - eq.fi << "\n";// 2 6 4
}