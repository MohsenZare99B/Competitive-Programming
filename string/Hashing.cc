//In The Name Of Allah
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())

int mpow(int a, int b, int m) {
  if (b == 0) return 1;
  int nesf = mpow(a, b / 2, m);
  if (b % 2 == 0) {
    return nesf * nesf % m;
  }
  return a * nesf % m * nesf % m;
}

class Hash {
  public:
    const int A1 = 970592641, B1 = 1e9 + 7,
              A2 = 1e9 + 9, B2 = 970592641;
    int n;
    string s;
    vector<int> h1, h2;
    Hash(string _s) {
      s = _s;
      n = sz(s);
      h1.resize(n);
      h2.resize(n);
      compute(h1, A1, B1);
      compute(h2, A2, B2);
    }

    void compute(vector<int> &h, const int &A, const int &B) {
      h[0] = s[0];
      for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * A + s[i]) % B;
      }
    }

    int get_h(vector<int> &h, int a, int b, const int &A, const int &B) {
      if (a == 0) {
        return h[b];
      }
      return ((h[b] - h[a - 1] * mpow(A, b - a + 1, B)) % B + B) % B;
    }
    
    int get_h1(int a, int b) {
      return get_h(h1, a, b, A1, B1);
    }

    int get_h2(int a, int b) {
      return get_h(h2, a, b, A2, B2);
    }
};
