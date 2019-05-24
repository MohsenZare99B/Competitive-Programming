#include<bits/stdc++.h>
using namespace std;

int myrandom (int i) { return rand()%i;}

signed main () {
  srand ( unsigned ( time(0) ) );
  vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  random_shuffle ( myvector.begin(), myvector.end(), myrandom);

  // print out content:
  cout << "myvector contains:";
  for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';

  return 0;
}