#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[20], f[(1 << 16)];

int ch(int state) {
  if (f[state] != -1) {
    return f[state];
  }
  int inc = 1;
  vi l;
  for (int i = 0; i < n; i++) {
    if (((state >> i) & 1) == 1) {
      l.push_back(a[i]);
    }
  }
  for (int i = 1; i < sz(l); i++) {
    if (l[i] < l[i - 1]) {
      inc = 0;
      break;
    }
  }
  if (inc) {
    return f[state] = 0;
  }
  int w = 0;
  for (int i = 0; i < n; i++) {
    if (((state >> i) & 1) == 1) {
      if (ch(state ^ (1 << i)) == 0) {
        w = 1;
        break;
      }
    }
  }
  return f[state] = w;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    f[i] = -1;
  }
  
  if (ch((1 << n) - 1)) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}