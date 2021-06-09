#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int K;
  cin >> K;
  int f = (1 << K) - 1;
  vector<int> o(f + 1), p(f + 1), l(f + 1), r(f + 1);
  vector<char> a(f + 1);
  vector<int> v;
  int cnt = (f + 1) / 2;
  for (int i = 1; i <= (f + 1) / 2; i++) {
    v.push_back(i);
  }
  while (cnt != f) {
    vector<int> tmp;
    for (int i = 0; i < (int)v.size(); i += 2) {
      cnt++;
      p[v[i]] = cnt;
      p[v[i + 1]] = cnt;
      l[cnt] = v[i];
      r[cnt] = v[i + 1];
      tmp.push_back(cnt);
    }
    v = tmp;
  }
  for (int i = 1; i <= f; i++) {
    char x;
    cin >> x;
    a[i] = x;
    if (i <= (1 << (K - 1))) {
      if (x == '?') {
        o[i] = 2;
      } else {
        o[i] = 1;
      }
    } else {
      if (x == '0') {
        o[i] = o[l[i]];
      } else if (x == '1') {
        o[i] = o[r[i]];
      } else {
        o[i] = o[l[i]] + o[r[i]];
      }
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    char x;
    cin >> n >> x;
    a[n] = x;
    while (n != 0) {
      if (n <= (f + 1) / 2) {
        if (a[n] == '?') {
          o[n] = 2;
        } else {
          o[n] = 1;
        }
      } else {
        if (a[n] == '0') {
          o[n] = o[l[n]];
        } else if (a[n] == '1') {
          o[n] = o[r[n]];
        } else {
          o[n] = o[l[n]] + o[r[n]];
        }
      }
      n = p[n];
    }
    cout << o[f] << '\n';
  }
}
